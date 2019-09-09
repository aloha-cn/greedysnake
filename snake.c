#include <stdlib.h>
#include "snake.h"

struct snakegame {
    int MOVE[4];

    int width;
    int height;
    int body[MAXSIZE];
    int length;
    int dir;
    int food;
};

struct snakegame *snake_create(int width, int height, int start, int length, int dir)
{
        struct snakegame *s;
        int i;

        s = malloc(sizeof(struct snakegame));
        if (!s) {
                return NULL;
        }

        s->MOVE[0] = 1; // right
        s->MOVE[1] = +width; // down
        s->MOVE[2] = -1; // left
        s->MOVE[3] = -width; // up
        s->length = length;
        s->dir = s->MOVE[dir];
        s->width = width;
        s->height = height;
        s->food = -1;
        // set up the body
        for (i = length - 1; i >= 0; i--) {
                s->body[i] = start;
                start += s->dir;
        }
        return s;
}

void snake_destroy(struct snakegame *s)
{
        free(s);
}

void snake_set_dir(struct snakegame *s, int dir)
{
	if (s->dir + s->MOVE[dir] != 0)
		s->dir = s->MOVE[dir];
}

void snake_set_food(struct snakegame *s, int food)
{
        s->food = food;
}

int snake_get_food(const struct snakegame *s)
{
        return s->food;
}

int snake_is_on_the_body(const struct snakegame *s, int pos)
{
        int i;

        for (i = 0; i < s->length; i++) {
                if (s->body[i] == pos) {
                        return 1;
                }
        }
        return 0;
}

int snake_step(struct snakegame *s)
{
    // calculate the new position
    int next_pos = s->body[0] + s->dir;
    int i;

    // move the snake first
    for (i = s->length; i>0; i--) s->body[i] = s->body[i-1];
    s->body[0] = -1;

    // check the new position
    if (next_pos < 0 || next_pos >= s->width*s->height || 
                    (s->dir == s->MOVE[0] && next_pos % s->width == 0) ||
                    (s->dir == s->MOVE[2] && (next_pos + 1) % s->width == 0) ||
                    snake_is_on_the_body(s, next_pos) ) {
        return 0; // game over
    }

    // accept the new position
    s->body[0] = next_pos;

    // check and eat the food
    if (s->food ==  next_pos) {
            s->length++;
            s->food = -1;
    }
    return 1;
}

