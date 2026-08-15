
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <curses.h>

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
	char ch = '@';
	mvprintw(head->y, head->x, " ");
	int max_x=0, max_y=0;
	getmaxyx(stdscr,max_y,max_x);
	switch (head->direction)
	{
		case LEFT:
		if(head->x <=0)
			head->x = max_x;
		mvprintw(head->y, --(head->x), "%c", ch);
		break;
		case RIGHT:
		mvprintw(head->y, ++(head->x), "%c", ch);
		break;
		case UP:
		mvprintw(--(head->y), head->x, "%c", ch);
		break;
		case DOWN:
		mvprintw(++(head->y), head->x, "%c", ch);
		break;
		default:
		break;
	}
}


int main(int argc, char **argv)
{
	control_buttons.up = KEY_UP;
	control_buttons.down = KEY_DOWN;
	control_buttons.left = KEY_LEFT;
	control_buttons.right = KEY_RIGHT;
	
	snake_t *snake = (snake_t*)malloc(sizeof(snake_t));
	initSnake(snake, START_TAIL_SIZE, 10, 10);
	
	initscr();
	keypad(stdscr,TRUE);
	raw();
	noecho();
	curs_set(FALSE);
	mvprintw(0,0,"Use arrows for control. Press 'F10' for EXIT");
	timeout(0);
	int key_pressed=0;
	while(key_pressed != STOP_GAME)
	{
		key_pressed = getch();
		go(snake);
		timeout(100);
	}
	free(snake->tail);
	free(snake);
	endwin();
	
	return 0;
}

