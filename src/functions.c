/*
** EPITECH PROJECT, 2017
** File Name : functions.c
** File description:
** By Arthur Teisseire
*/

#include "framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *buffer = malloc(sizeof(framebuffer_t));

	buffer->width = width;
	buffer->height = height;
	buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
	init(buffer);
	return (buffer);
}

void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
	unsigned int pos_x = x * 4;
	unsigned int pos_y = buffer->width * y * 4;

	buffer->pixels[pos_y + pos_x] = color.r;
	buffer->pixels[pos_y + pos_x + 1] = color.g;
	buffer->pixels[pos_y + pos_x + 2] = color.b;
	buffer->pixels[pos_y + pos_x + 3] = color.a;
}

void init(framebuffer_t *buffer)
{
	int size = buffer->height * buffer->width * 4;

	for (int i = 0; i < size; i++)
		buffer->pixels[i] = 0;
}
