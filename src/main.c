/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include "framebuffer.h"

int main(void)
{
	sfVideoMode mode = {SIZE_X, SIZE_Y, 32};
	sfRenderWindow *window;
	sfEvent event;
	sfTexture *texture = sfTexture_create(SIZE_X, SIZE_Y);
	sfSprite *sprite = sfSprite_create();
	framebuffer_t *buffer = framebuffer_create(SIZE_X, SIZE_Y);

	window = sfRenderWindow_create(mode, "Print pixel", sfResize | sfClose, NULL);
	if (!window)
		return (84);

	while (sfRenderWindow_isOpen(window))
	{
		/* Process events */
		while (sfRenderWindow_pollEvent(window, &event))
		{
			/* Close window : exit */
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		/* Clear the screen */
		sfRenderWindow_clear(window, sfBlack);

		my_put_pixel(buffer, 1, 1, sfRed);
		my_put_pixel(buffer, 0, 0, sfRed);
		my_put_square(buffer, 20, 20, 50, 200, sfRed);
		my_put_square(buffer, 500, 400, 200, 70, sfRed);
		sfTexture_updateFromPixels(texture, buffer->pixels, SIZE_X, SIZE_Y, 0, 0);
		sfSprite_setTexture(sprite, texture, 1);
		sfRenderWindow_drawSprite(window, sprite, NULL);

		/* Update the window */
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
