#include "function.h"



int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	initscr();
	keypad(stdscr, TRUE);
	raw();
	noecho();
	curs_set(FALSE);

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

	int game_mode = 1;
	int snake1_color = 3;
	int difficulty = 1;

	startMenu(&game_mode, &snake1_color, &difficulty);

	clock_t delay = CLOCKS_PER_SEC / 5;
	if (difficulty == 2)
		delay = CLOCKS_PER_SEC / 10;
	if (difficulty == 3)
		delay = CLOCKS_PER_SEC / 16;

	control_buttons.up = KEY_UP;
	control_buttons.down = KEY_DOWN;
	control_buttons.left = KEY_LEFT;
	control_buttons.right = KEY_RIGHT;


	snake_t *snake1 = (snake_t *)malloc(sizeof(snake_t));
	initSnake(snake1, START_TAIL_SIZE, 10, 10);
	snake1->controls = control_buttons;
	snake1->color_pair = snake1_color;


	snake_t *snake2 = NULL;
	if (game_mode == 2)
	{
		snake2 = (snake_t *)malloc(sizeof(snake_t));
		initSnake(snake2, START_TAIL_SIZE, 20, 20);
		snake2->controls = controls_player2; 
		snake2->direction = RIGHT;
		snake2->color_pair = (snake1_color == 4) ? 5 : 4;
	}

	food_t food[FOOD_COUNT];

	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);


	for (int i = 0; i < FOOD_COUNT; i++)
	{
		spawnFood(&food[i], snake1, max_x, max_y);
	}

	mvprintw(1, 1, "Use arrows for control. Press 'F10' for EXIT");
	timeout(0);

	attron(COLOR_PAIR(1));
	box(stdscr, '*', '*');

	clock_t last_step_time = clock();
	int key_pressed = 0;

	while (key_pressed != STOP_GAME)
	{
		key_pressed = getch();

		attron(COLOR_PAIR(2));
		for (int i = 0; i < FOOD_COUNT; i++)
		{
			mvaddch(food[i].y, food[i].x, '@');
		}
		attron(COLOR_PAIR(1));

		clock_t current_time = clock();
		if (current_time - last_step_time >= delay)
		{

			int old_x1 = snake1->x;
			int old_y1 = snake1->y;
			go(snake1);
			goTail(snake1, old_x1, old_y1);


			if (snake2 != NULL)
			{
				autoPilot(snake2, food, FOOD_COUNT, max_x, max_y);

				int old_x2 = snake2->x;
				int old_y2 = snake2->y;
				go(snake2);
				goTail(snake2, old_x2, old_y2);
			}

			for (int i = 0; i < FOOD_COUNT; i++)
			{
				if (snake1->x == food[i].x && snake1->y == food[i].y)
				{
					snake1->tsize++;
					snake1->tail = realloc(snake1->tail, snake1->tsize * sizeof(tail_t));
					spawnFood(&food[i], snake1, max_x, max_y);
				}

				if (snake2 != NULL && snake2->x == food[i].x && snake2->y == food[i].y)
				{
					snake2->tsize++;
					snake2->tail = realloc(snake2->tail, snake2->tsize * sizeof(tail_t));
					spawnFood(&food[i], snake2, max_x, max_y);
				}
			}
			last_step_time = current_time;
		}
		changeDirection(snake1, key_pressed);
		// if (snake2 != NULL)
		// {
		// 	changeDirection(snake2, key_pressed);
		// }
		if (isCrush(snake1) || (snake2 != NULL && isCrush(snake2)))
			break;
	}

	free(snake1->tail);
	free(snake1);
	if (snake2 != NULL)
	{
		free(snake2->tail);
		free(snake2);
	}
	endwin();
	return 0;
}