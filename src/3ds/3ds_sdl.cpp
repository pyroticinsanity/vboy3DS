#include "3ds_vb_sdl.h"

#include "3ds_sdl.h"

// The Wii surface
SDL_Surface *back_surface = NULL;

int wii_sdl_init()
{
	int returnCode = wii_sdl_handle_init();

	SDL_ShowCursor(SDL_DISABLE);

	return returnCode;
}

void wii_sdl_free_resources()
{
	if(back_surface != NULL)
	{
		SDL_FreeSurface(back_surface);
	}
}