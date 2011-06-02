/*
WiirtualBoy : Wii port of the Mednafen Virtual Boy emulator

Copyright (C) 2011
raz0red (www.twitchasylum.com)

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1.	The origin of this software must not be misrepresented; you
must not claim that you wrote the original software. If you use
this software in a product, an acknowledgment in the product
documentation would be appreciated but is not required.

2.	Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3.	This notice may not be removed or altered from any source
distribution.
*/

#ifndef WII_VB_H
#define WII_VB_H

#include <wiiuse/wpad.h>
#include "wii_main.h"

// FPS
#define DEFAULT_FPS 60

// Virtual boy size
#define VB_WIDTH 384
#define VB_HEIGHT 224

// Default screen size
#define DEFAULT_SCREEN_X ((int)(VB_WIDTH*1.3))
#define DEFAULT_SCREEN_Y ((int)(VB_HEIGHT*1.3))

#define WII_BUTTON_VB_START ( WPAD_BUTTON_PLUS | WPAD_CLASSIC_BUTTON_PLUS )
#define GC_BUTTON_VB_START ( PAD_BUTTON_START )
#define WII_BUTTON_VB_SELECT ( WPAD_BUTTON_MINUS | WPAD_CLASSIC_BUTTON_MINUS )
#define GC_BUTTON_VB_SELECT ( PAD_BUTTON_Y )

#define WII_BUTTON_VB_L ( WPAD_BUTTON_B | WPAD_CLASSIC_BUTTON_FULL_L )
#define GC_BUTTON_VB_L ( PAD_TRIGGER_L )
#define WII_BUTTON_VB_R ( WPAD_BUTTON_A | WPAD_CLASSIC_BUTTON_FULL_R )
#define GC_BUTTON_VB_R ( PAD_TRIGGER_R )

#define WII_BUTTON_VB_A ( WPAD_BUTTON_2 )
#define WII_CLASSIC_VB_A ( WPAD_CLASSIC_BUTTON_A )
#define WII_NUNCHUK_VB_A ( WPAD_NUNCHUK_BUTTON_C )
#define GC_BUTTON_VB_A ( PAD_BUTTON_A )
#define WII_BUTTON_VB_B ( WPAD_BUTTON_1 ) 
#define WII_CLASSIC_VB_B ( WPAD_CLASSIC_BUTTON_B )
#define WII_NUNCHUK_VB_B ( WPAD_NUNCHUK_BUTTON_Z )
#define GC_BUTTON_VB_B ( PAD_BUTTON_B )

// The last cartridge hash
extern char wii_cartridge_hash[33];
// Whether to display debug info (FPS, etc.)
extern BOOL wii_debug;
// Hardware buttons (reset, power, etc.)
extern u8 wii_hw_button;
// Auto load state?
extern BOOL wii_auto_load_state;
// Auto save state?
extern BOOL wii_auto_save_state;
// The screen X size
extern int wii_screen_x;
// The screen Y size
extern int wii_screen_y;
// Maximum frame rate
extern u8 wii_max_frames;


/*
 * Returns the roms directory
 *
 * return   The roms directory
 */
extern char* wii_get_roms_dir();

/*
 * Returns the saves directory
 *
 * return   The saves directory
 */
extern char* wii_get_saves_dir();

/*
 * Returns the base directory
 *
 * return   The bae directory
 */
extern char* wii_get_base_dir();
#endif
