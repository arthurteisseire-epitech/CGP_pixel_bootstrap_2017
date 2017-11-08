/*
** EPITECH PROJECT, 2017
** File Name : framebuffer.h
** File description:
** By Arthur Teisseire
*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#define SIZE_X 800
#define SIZE_Y 600

#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);
void my_put_square(framebuffer_t *buffer, unsigned int x, unsigned int y, unsigned int size_x, unsigned int size_b, sfColor color);
void init(framebuffer_t *buffer);

#endif
