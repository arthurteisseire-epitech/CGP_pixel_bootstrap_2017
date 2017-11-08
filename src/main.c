/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include "framebuffer.h"

int main(void)
{
	sfVideoMode mode = {3, 5, 32};
	sfRenderWindow *window;
	sfEvent event;
	sfTexture *texture = sfTexture_create(3, 5);
	sfSprite *sprite = sfSprite_create();
	framebuffer_t *buffer = framebuffer_create(3, 5);

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
		sfTexture_updateFromPixels(texture, buffer->pixels, 3, 5, 0, 0);
		sfSprite_setTexture(sprite, texture, 1);
		sfRenderWindow_drawSprite(window, sprite, NULL);

		/* Update the window */
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
