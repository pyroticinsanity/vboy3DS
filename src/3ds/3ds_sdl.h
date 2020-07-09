#ifndef N3DS_SDL_H
#define N3DS_SDL_H

#include <SDL.h>
#include <SDL_ttf.h>

// The Wii surface
extern SDL_Surface* back_surface;

extern int wii_sdl_init();

extern void wii_sdl_free_resources();

#endif