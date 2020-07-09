
#include "3ds_sdl.h"
#include "3ds_vb.h"

// The original 8bpp palette
SDL_Palette orig_8bpp_palette;
SDL_Color orig_8bpp_colors[512];

/*
 * Initializes the SDL
 */
int wii_sdl_handle_init()
{
  if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) 
  {
    return 0;
  }

  if( SDL_InitSubSystem( SDL_INIT_VIDEO ) < 0 ) 
  {
    return 0;
  }

  back_surface = 
    SDL_SetVideoMode(
      VB_WIDTH,
      VB_HEIGHT, 
#if BPP == 8
      8,
#elif BPP == 16
      16, 
#else 
      32,
#endif
      SDL_HWSURFACE
    );

  if( !back_surface) 
  {
    return 0;
  }

#if BPP == 8
  int ncolors = back_surface->format->palette->ncolors;
  memcpy( orig_8bpp_colors, 
    back_surface->format->palette->colors, 
    ncolors * sizeof(SDL_Color) );
  orig_8bpp_palette.colors = orig_8bpp_colors;
  orig_8bpp_palette.ncolors = ncolors;
#endif

  return 1;
}