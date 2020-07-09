#include "3ds_vb_main.h"
#include "3ds_sdl.h"

char* wii_get_base_dir()
{
	return "/3ds/vboy3ds";
}

int wii_get_render_rate()
{
  return -1;
}

void wii_handle_init()
{
	if(!wii_sdl_init())
	{
		printf("FAILED: Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}

	wii_vb_init();	
}

void wii_handle_free_resources()
{
	wii_vb_free();

	//wii_sdl_free_resources();

	SDL_Quit();
}