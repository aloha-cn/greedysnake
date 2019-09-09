#ifndef __SNAKE_H
#define __SNAKE_H

#define MAXSIZE 1024

struct snakegame;

/* Create a snake game (without food being set)
 * width:  width of the room
 * height: height of the room
 * start:  initial position of the tail of the snake, 0 ~ (w * h - 1)
 * length: initial length of the the snake
 * dir:    initial direction of the the snake
 *         (0: right, 1: down, 2: left, 3: up) */
struct snakegame *snake_create(int width, int height, int start, int length, int dir);

/* Destroy a snake game */
void snake_destroy(struct snakegame *s);


/* Change direction of the snake
 * dir:    direction
 *         (0: right, 1: down, 2: left, 3: up) */
void snake_set_dir(struct snakegame *s, int dir);

/* Set the position of food
 * food: position of the food */
void snake_set_food(struct snakegame *s, int food);

/* Get the position of food
 * or return -1 if no food is set */
int snake_get_food(const struct snakegame *s);

/* Check if the position is on the body of the snake */
int snake_is_on_the_body(const struct snakegame *s, int pos);

/* one step forward */
int snake_step(struct snakegame *s);

#endif // __SNAKE_H

