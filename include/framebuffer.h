/*
** EPITECH PROJECT, 2017
** File Name : framebuffer.h
** File description:
** By Arthur Teisseire
*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);
void init(framebuffer_t *buffer);

#endif
