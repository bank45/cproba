#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>


#define MIN_Y 2

enum
{
	LEFT = 1,
	UP,
	RIGHT,
	DOWN,
	STOP_GAME = KEY_F(10)
};
enum
{
	MAX_TAIL_SIZE = 100,
	START_TAIL_SIZE = 3,
	MAX_FOOD_SIZE = 200,
	FOOD_EXPIRE_SECONDS = 10,
	FOOD_COUNT = 5
};

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
	.right = 'd'};

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

typedef struct
{
	int x;
	int y;
} food_t;

void initTail(struct tail_t t[], size_t size)
{
	struct tail_t init_t = {0, 0};
	for (size_t i = 0; i < size; i++)
	{
		t[i] = init_t;
	}
}

void initHead(struct snake_t *head, int x, int y)
{
	head->x = x;
	head->y = y;
	head->direction = LEFT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
	tail_t *tail = (tail_t *)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
	initTail(tail, MAX_TAIL_SIZE);
	initHead(head, x, y);
	head->tail = tail;
	head->tsize = size + 1;
}

void go(struct snake_t *head)
{
	char ch = 'Z';
	mvprintw(head->y, head->x, " ");
	int max_x = 0, max_y = 0;
	getmaxyx(stdscr, max_y, max_x);

	attron(COLOR_PAIR(head->color_pair));

	switch (head->direction)
	{
	case LEFT:
		if (head->x <= 1)
			head->x = max_x - 1;
		mvprintw(head->y, --(head->x), "%c", ch);
		break;
	case RIGHT:
		if (head->x >= max_x - 2)
			head->x = 1;
		mvprintw(head->y, ++(head->x), "%c", ch);
		break;
	case UP:
		if (head->y <= MIN_Y)
			head->y = max_y - 2;
		mvprintw(--(head->y), head->x, "%c", ch);
		break;
	case DOWN:
		if (head->y >= max_y - 2)
			head->y = MIN_Y;
		mvprintw(++(head->y), head->x, "%c", ch);
		break;
	default:
		break;
	}
	attroff(COLOR_PAIR(head->color_pair));
}

void goTail(struct snake_t *head, int old_x, int old_y)
{
	char ch = '*';

	head->tail[0].x = old_x;
	head->tail[0].y = old_y;

	mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");

	attron(COLOR_PAIR(head->color_pair));

	for (size_t i = head->tsize - 1; i > 0; i--)
	{
		head->tail[i] = head->tail[i - 1];
		if (head->tail[i].y || head->tail[i].x)
			mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
	}

	attroff(COLOR_PAIR(head->color_pair));

	head->tail[0].x = head->x;
	head->tail[0].y = head->y;
}

int32_t checkDirection(snake_t *snake, int32_t key)
{
	if (snake->direction == UP && key == DOWN)
	{
		return snake->direction;
	}
	if (snake->direction == DOWN && key == UP)
	{
		return snake->direction;
	}
	if (snake->direction == LEFT && key == RIGHT)
	{
		return snake->direction;
	}
	if (snake->direction == RIGHT && key == LEFT)
	{
		return snake->direction;
	}

	return key;
}

void changeDirection(snake_t *snake, const int32_t key)
{
	int requested_direction = -1;
	int low_key = tolower(key);

	if (key == snake->controls.down || low_key == snake->controls.down)
	{
		requested_direction = DOWN;
	}
	else if (key == snake->controls.up || low_key == snake->controls.up)
	{
		requested_direction = UP;
	}
	else if (key == snake->controls.right || low_key == snake->controls.right)
	{
		requested_direction = RIGHT;
	}
	else if (key == snake->controls.left || low_key == snake->controls.left)
	{
		requested_direction = LEFT;
	}

	if (requested_direction != -1)
	{
		snake->direction = checkDirection(snake, requested_direction);
	}
}

void spawnFood(food_t *food, const snake_t *snake, int width, int height)
{
	int is_on_snake;

	do
	{
		is_on_snake = 0;

		food->x = 2 + rand() % (width - 4);
		food->y = MIN_Y + 1 + rand() % (height - MIN_Y - 2);

		if (food->x == snake->x && food->y == snake->y)
		{
			is_on_snake = 1;
			continue;
		}

		if (snake->tail != NULL)
		{
			for (size_t i = 0; i < snake->tsize; i++)
			{
				if (food->x == snake->tail[i].x && food->y == snake->tail[i].y)
				{
					is_on_snake = 1;
					break;
				}
			}
		}

	} while (is_on_snake);
}

int isCrush(snake_t *snake)
{
	for (size_t i = 1; i < snake->tsize; i++)
	{
		if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
		{
			return 0; 
		}
	}
	return 0;
}

void startMenu(int *mode, int *color, int *diff)
{
	clear();
	timeout(-1);
	curs_set(TRUE);

	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	int start_y = max_y / 2 - 6;
	int start_x = max_x / 2 - 20;

	attron(A_BOLD | COLOR_PAIR(1));
	mvprintw(start_y, start_x, "-==*** ДОБРО ПОЖАЛОВАТЬ В ИГРУ ЗМЕЙКУ ***==-");
	attroff(A_BOLD | COLOR_PAIR(1));

	mvprintw(start_y + 3, start_x, "1. Выберите режим игры:");
	mvprintw(start_y + 4, start_x + 4, "[1] Один игрок");
    mvprintw(start_y + 5, start_x + 4, "[2] Играть против ИИ-Бота");
	mvprintw(start_y + 6, start_x, "Введите цифру (1-2): ");
	echo();
	int ch = getch();
	if (ch == '2')
		*mode = 2;
	else
		*mode = 1;

	noecho();
	clear();
	mvprintw(start_y, start_x, "2. Выберите цвет вашей змейки:");

	attron(COLOR_PAIR(3));
	mvprintw(start_y + 2, start_x + 4, "[G] Зеленый");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
	mvprintw(start_y + 3, start_x + 4, "[C] Голубой");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(5));
	mvprintw(start_y + 4, start_x + 4, "[M] Фиолетовый");
	attroff(COLOR_PAIR(5));

	mvprintw(start_y + 6, start_x, "Нажмите букву цвета: ");
	ch = tolower(getch());
	if (ch == 'c')
		*color = 4;
	else if (ch == 'm')
		*color = 5;
	else
		*color = 3;

	clear();
	mvprintw(start_y, start_x, "3. Выберите уровень сложности:");
	mvprintw(start_y + 2, start_x + 4, "[1] Новичок (Медленно)");
	mvprintw(start_y + 3, start_x + 4, "[2] Геймер (Средне)");
	mvprintw(start_y + 4, start_x + 4, "[3] Киберспортсмен (Быстро)");
	mvprintw(start_y + 6, start_x, "Введите уровень (1-3): ");
	ch = getch();
	if (ch == '2')
		*diff = 2;
	else if (ch == '3')
		*diff = 3;
	else
		*diff = 1;

	clear();
	noecho();
	curs_set(FALSE);
	timeout(0);
}

void autoPilot(snake_t* snake, food_t food_array[], int food_count, int width, int height)
{
    if (snake == NULL) return;

    food_t closest_food = food_array[0];
    int min_distance = abs(snake->x - food_array[0].x) + abs(snake->y - food_array[0].y);

    for (int i = 1; i < food_count; i++) {
        int dist = abs(snake->x - food_array[i].x) + abs(snake->y - food_array[i].y);
        if (dist < min_distance) {
            min_distance = dist;
            closest_food = food_array[i];
        }
    }

    int best_direction = snake->direction;

    if (snake->x < closest_food.x && snake->direction != LEFT)       best_direction = RIGHT;
    else if (snake->x > closest_food.x && snake->direction != RIGHT)  best_direction = LEFT;
    else if (snake->y < closest_food.y && snake->direction != UP)     best_direction = DOWN;
    else if (snake->y > closest_food.y && snake->direction != DOWN)    best_direction = UP;

    int next_x = snake->x;
    int next_y = snake->y;

    if (best_direction == LEFT)  next_x--;
    if (best_direction == RIGHT) next_x++;
    if (best_direction == UP)    next_y--;
    if (best_direction == DOWN)  next_y++;

    int will_crash = 0;
    for (size_t i = 1; i < snake->tsize; i++) {
        if (next_x == snake->tail[i].x && next_y == snake->tail[i].y) {
            will_crash = 1;
            break;
        }
    }

    if (will_crash) {
        int directions[4] = {UP, DOWN, LEFT, RIGHT};
        for (int d = 0; d < 4; d++) {
            if (checkDirection(snake, directions[d]) == snake->direction) continue;

            int test_x = snake->x;
            int test_y = snake->y;
            if (directions[d] == LEFT)  test_x--;
            if (directions[d] == RIGHT) test_x++;
            if (directions[d] == UP)    test_y--;
            if (directions[d] == DOWN)  test_y++;

            int safe = 1;
            for (size_t i = 1; i < snake->tsize; i++) {
                if (test_x == snake->tail[i].x && test_y == snake->tail[i].y) {
                    safe = 0;
                    break;
                }
            }
            if (safe) {
                best_direction = directions[d];
                break;
            }
        }
    }

    snake->direction = checkDirection(snake, best_direction);
}
