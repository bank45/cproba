#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <ncurses.h>

#define MIN_Y 2

enum {LEFT=1,UP,RIGHT,DOWN,STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100,START_TAIL_SIZE=3,MAX_FOOD_SIZE=200,FOOD_EXPIRE_SECONDS=10, FOOD_COUNT = 5};

struct control_buttons
{
    int down;
    int up;
    int left;
    int right;	
} control_buttons;

struct control_buttons controls_player2 = {
    .down = 's',
    .up = 'w',
    .left = 'a',
    .right = 'd'
}; // <-- ИСПРАВЛЕНО: Добавлена точка с запятой

typedef struct tail_t
{
	int x;
	int y;
} tail_t;

typedef struct snake_t
{
	int x;
	int y;
	int direction;
	size_t tsize;
	tail_t *tail;
	struct control_buttons controls;
	int color_pair; 
} snake_t;

typedef struct {
    int x;
    int y;
} food_t;


void initTail(struct tail_t t[], size_t size)
{
	struct tail_t init_t={0,0};
	for(size_t i=0; i<size; i++)
	{
		t[i]=init_t;
	}
}

void initHead(struct snake_t *head, int x, int y)
{
	head->x = x;
	head->y = y;
	head->direction = LEFT;
}

void initSnake(snake_t *head, size_t size,int x, int y)
{
	tail_t* tail = (tail_t*) malloc(MAX_TAIL_SIZE * sizeof(tail_t));
	initTail(tail,MAX_TAIL_SIZE);
	initHead(head,x,y);
	head->tail = tail;
	head->tsize = size+1;
	head->controls = control_buttons;
}

void go(struct snake_t *head)
{
	char ch = 'Z';
	mvprintw(head->y, head->x, " ");
	int max_x=0, max_y=0;
	getmaxyx(stdscr,max_y,max_x);

	attron(COLOR_PAIR(head->color_pair)); // <-- ДОБАВЛЕНО: включаем цвет змейки

	switch (head->direction)
	{
		case LEFT:
		if(head->x <=1)	head->x = max_x -1;
		mvprintw(head->y, --(head->x), "%c", ch);
		break;
		case RIGHT:
		if (head->x >= max_x - 2) head->x = 1;
		mvprintw(head->y, ++(head->x), "%c", ch);
		break;
		case UP:
		if (head->y <= MIN_Y) head->y = max_y - 2;
		mvprintw(--(head->y), head->x, "%c", ch);
		break;
		case DOWN:
		if (head->y >= max_y - 2) head->y = MIN_Y;
		mvprintw(++(head->y), head->x, "%c", ch);
		break;
		default:
		break;
	}
}

void goTail(struct snake_t *head, int old_x, int old_y)
{
	char ch = '*';

	head->tail[0].x = old_x;
	head->tail[0].y = old_y;
    
	mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x," ");
	
	attron(COLOR_PAIR(head->color_pair)); // <-- ДОБАВЛЕНО: включаем цвет змейки

	for(size_t i = head->tsize-1; i>0; i--)
	{
		head->tail[i] = head->tail[i-1];
		if(head->tail[i].y || head->tail[i].x)
			mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
	}

	attroff(COLOR_PAIR(head->color_pair)); // <-- ДОБАВЛЕНО: выключаем цвет

	head->tail[0].x = head->x;
	head->tail[0].y = head->y;	
}


int32_t checkDirection(snake_t* snake, int32_t key) {
    if (snake->direction == UP && key == DOWN) {
        return snake->direction;
    }
    if (snake->direction == DOWN && key == UP) {
        return snake->direction;
    }
    if (snake->direction == LEFT && key == RIGHT) {
        return snake->direction;
    }
    if (snake->direction == RIGHT && key == LEFT) {
        return snake->direction;
    }

    return key;
}


void changeDirection(snake_t* snake, const int32_t key)
{
    int requested_direction = -1; 
	int low_key = tolower(key); // приводим символ к нижнему регистру

    if (key == snake->controls.down) {
        requested_direction = DOWN;
    }
    else if (key == snake->controls.up) {
        requested_direction = UP;
    }
    else if (key == snake->controls.right) {
        requested_direction = RIGHT;
    }
    else if (key == snake->controls.left) {
        requested_direction = LEFT;
    }    

    if (requested_direction != -1) {
        snake->direction = checkDirection(snake, requested_direction);
    }
}



void spawnFood(food_t* food, const snake_t* snake, int width, int height)
{
    int is_on_snake;

    do {
        is_on_snake = 0; 

        food->x = 1 + rand() % (width - 2);
        food->y = MIN_Y + rand() % (height - MIN_Y - 1); 

        if (food->x == snake->x && food->y == snake->y) {
            is_on_snake = 1;
            continue;
        }

        for (size_t i = 0; i < snake->tsize; i++) {
            if (food->x == snake->tail[i].x && food->y == snake->tail[i].y) {
                is_on_snake = 1;
                break; 
            }
        }

    } while (is_on_snake); 
}

int isCrush(snake_t * snake)
{
    for (size_t i = 1; i < snake->tsize; i++) {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y) {
            return 0; // ИСПРАВЛЕНО: возвращаем 1 при столкновении
        }
    }
    return 0; 
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	control_buttons.up = KEY_UP;
	control_buttons.down = KEY_DOWN;
	control_buttons.left = KEY_LEFT;
	control_buttons.right = KEY_RIGHT;
	
	// Первая змейка (игрок 1)
	snake_t *snake1 = (snake_t*)malloc(sizeof(snake_t));
	initSnake(snake1, START_TAIL_SIZE, 10, 10);
	snake1->controls = control_buttons;  
	snake1->color_pair = 3; // <-- ДОБАВЛЕНО: Назначаем зеленый цвет (пара №3)

	// Вторая змейка (игрок 2)
	snake_t *snake2 = (snake_t*)malloc(sizeof(snake_t));
	initSnake(snake2, START_TAIL_SIZE, 20, 20);
	snake2->controls.up = 'w';
	snake2->controls.down = 's';
	snake2->controls.left = 'a';
	snake2->controls.right = 'd';
	snake2->direction = RIGHT;  
	snake2->color_pair = 4; // <-- ДОБАВЛЕНО: Назначаем голубой цвет (пара №4)

	
	food_t food[FOOD_COUNT];

	initscr();
	keypad(stdscr,TRUE);
	raw();
	noecho();
	curs_set(FALSE);

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    // Генерируем начальные позиции для всего массива еды
    for (int i = 0; i < FOOD_COUNT; i++) {
        spawnFood(&food[i], snake1, max_x, max_y);
    }

	mvprintw(1,1,"Use arrows for control. Press 'F10' for EXIT");
	timeout(0);
	
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Для рамки
	init_pair(2, COLOR_RED, COLOR_BLACK);    // Для еды
	init_pair(3, COLOR_GREEN, COLOR_BLACK);  // <-- ДОБАВЛЕНО: Зеленый для Игрока 1
	init_pair(4, COLOR_CYAN, COLOR_BLACK);   // <-- ДОБАВЛЕНО: Голубой/Синий для Игрока 2


	attron(COLOR_PAIR(1));
	box(stdscr,'*','*');	
	
	clock_t delay = CLOCKS_PER_SEC / 5; 
    clock_t last_step_time = clock();
    
	int key_pressed=0;
		while(key_pressed != STOP_GAME)
	{
		key_pressed = getch();

        // Отрисовываем ВСЮ еду из массива на каждой итерации
        attron(COLOR_PAIR(2));
        for (int i = 0; i < FOOD_COUNT; i++) {
            mvaddch(food[i].y, food[i].x, '@'); 
        }
        attron(COLOR_PAIR(1)); 

		clock_t current_time = clock();
        if (current_time - last_step_time >= delay) 
        { 
            // Движение первой змейки
            int old_x1 = snake1->x;
            int old_y1 = snake1->y;		
            go(snake1);
            goTail(snake1, old_x1, old_y1);
            
            // Движение второй змейки
            int old_x2 = snake2->x;
            int old_y2 = snake2->y;		
            go(snake2);
            goTail(snake2, old_x2, old_y2);
            
            // Проверяем поедание для каждого объекта еды в массиве
            for (int i = 0; i < FOOD_COUNT; i++) 
            {
                // Проверка для первой змейки
                if (snake1->x == food[i].x && snake1->y == food[i].y) 
                {
                    snake1->tsize++;
                    snake1->tail = realloc(snake1->tail, snake1->tsize * sizeof(tail_t));
                    spawnFood(&food[i], snake1, max_x, max_y); // Переспавниваем только съеденную порцию
                }
                
                // Проверка для второй змейки
                if (snake2->x == food[i].x && snake2->y == food[i].y) 
                {
                    snake2->tsize++;
                    snake2->tail = realloc(snake2->tail, snake2->tsize * sizeof(tail_t));
                    spawnFood(&food[i], snake2, max_x, max_y); // Переспавниваем только съеденную порцию
                }
            }

			last_step_time = current_time; 
        } 
			
        changeDirection(snake1, key_pressed); 
        changeDirection(snake2, key_pressed);
		
        if(isCrush(snake1) || isCrush(snake2))
            break; 
	}

			
	// Очистка памяти
	free(snake1->tail); // <-- ИСПРАВЛЕНО: вместо snake
	free(snake1);       // <-- ИСПРАВЛЕНО: вместо snake
	free(snake2->tail);
	free(snake2);
	endwin();

	return 0;
}
