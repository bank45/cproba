
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <pdcurses.h>

#define MIN_Y 2

enum {LEFT=1,UP,RIGHT,DOWN,STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100,START_TAIL_SIZE=3,MAX_FOOD_SIZE=200,FOOD_EXPIRE_SECONDS=10};

struct control_buttons
{
int down;
int up;
int left;
int right;	
} control_buttons;

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
	for(size_t i = head->tsize-1; i>0; i--)
	{
		head->tail[i] = head->tail[i-1];
		if(head->tail[i].y || head->tail[i].x)
			mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
	}
	head->tail[0].x = head->x;
	head->tail[0].y = head->y;	
}

// void changeDirection(snake_t* snake, const int32_t key)
// {
// 	if(key == snake->controls.down && snake->direction != UP)
// 		snake->direction = DOWN;
// 	else if (key == snake->controls.up && snake->direction != DOWN)
// 		snake->direction = UP;
// 	else if (key == snake->controls.right && snake->direction != LEFT)
// 		snake->direction = RIGHT;
// 		else if (key == snake->controls.left && snake->direction != RIGHT)
// 		snake->direction = LEFT;	
// }

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
    int low_key = tolower(key);
    int requested_direction = -1; 

    if (key == snake->controls.down || low_key == 's') {
        requested_direction = DOWN;
    }
    else if (key == snake->controls.up || low_key == 'w') {
        requested_direction = UP;
    }
    else if (key == snake->controls.right || low_key == 'd') {
        requested_direction = RIGHT;
    }
    else if (key == snake->controls.left || low_key == 'a') {
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


int main(int argc, char **argv)
{
	srand(time(NULL));

	control_buttons.up = KEY_UP;
	control_buttons.down = KEY_DOWN;
	control_buttons.left = KEY_LEFT;
	control_buttons.right = KEY_RIGHT;
	
	snake_t *snake = (snake_t*)malloc(sizeof(snake_t));
	initSnake(snake, START_TAIL_SIZE, 10, 10);
	
	food_t food;

	initscr();
	keypad(stdscr,TRUE);
	raw();
	noecho();
	curs_set(FALSE);

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    spawnFood(&food, snake, max_x, max_y);

	mvprintw(1,1,"Use arrows for control. Press 'F10' for EXIT");
	timeout(0);
	
	start_color();
	init_pair(1, COLOR_YELLOW , COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK); 

	attron(COLOR_PAIR(1));
	box(stdscr,'*','*');	
	
	timeout(0);
	clock_t delay = CLOCKS_PER_SEC / 5; 
    clock_t last_step_time = clock();
    
	int key_pressed=0;
	while(key_pressed != STOP_GAME)
	{
		key_pressed = getch();

        attron(COLOR_PAIR(2));
        mvaddch(food.y, food.x, '@'); 
        attron(COLOR_PAIR(1)); 

		
		clock_t current_time = clock();
        if (current_time - last_step_time >= delay) 
			{
			int old_x = snake->x;
			int old_y = snake->y;		
			go(snake);
			goTail(snake,old_x,old_y);

            if (snake->x == food.x && snake->y == food.y) 
            {
                snake->tsize++;
                snake->tail = realloc(snake->tail, snake->tsize * sizeof(tail_t));
                
                spawnFood(&food, snake, max_x, max_y);
            }

			last_step_time = current_time; 
			}
		changeDirection(snake, key_pressed);
	}
	free(snake->tail);
	free(snake);
	endwin();
	
	return 0;
}

