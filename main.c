#include <stdio.h>
#include <stdlib.h>

#include "snake.h"

void draw(const struct snakegame *s, int w, int h)
{
        int i, j;
        for (i = 0; i < w+2; i++) printf("_");
        printf("\n");
        for (i = 0; i < h; i++) {
                printf("|");
                for (j = 0; j < w; j++) {
                        int pos = i * w + j;
                        if (pos == snake_get_food(s)) {
                                printf("0");
                        } else if (snake_is_on_the_body(s, pos)) {
                                printf("*");
                        } else {
                                printf(" ");
                        }
                }
                printf("|\n");
        }
        for (i = 0; i < w+2; i++) printf("-");
        printf("\n");
}

#define WIDTH 20
#define HEIGHT 15 

int main()
{
        struct snakegame *game;

        /* Create a new game with size W * H */
        game = snake_create(WIDTH, HEIGHT, 45, 3, 0);

        do {
                int d;
                int food;
                if (snake_get_food(game) == -1) {
                        /* generate a food randomly */
                        do {
                                food = rand()/1024*WIDTH*HEIGHT/(RAND_MAX/1024+1);
                        } while (snake_is_on_the_body(game, food));
                        snake_set_food(game, food);
                }
                draw(game, WIDTH, HEIGHT);
                d = getchar();
                while(getchar() != '\n');
                switch (d) {
                        case 'r':
                        case 'f':
                                snake_set_dir(game, 0);
                                break;
                        case 'd':
                        case 's':
                                snake_set_dir(game, 1);
                                break;
                        case 'l':
                        case 'a':
                                snake_set_dir(game, 2);
                                break;
                        case 'u':
                        case 'w':
                                snake_set_dir(game, 3);
                                break;
                        case 'q':
                                printf("quit game\n");
                                goto end_game;
                        default:
                                /* keep direction */
                                break;
                }
        } while (snake_step(game));

        printf("game over\n");

end_game:
        snake_destroy(game);

        return 0;
}

