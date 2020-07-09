#ifndef N3DS_VB_MAIN_H
#define N3DS_VB_MAIN_H

#include <stdio.h>

/*
 * Initializes the emulator
 */
extern void wii_vb_init(); // TODO

/*
 * Free resources (closes) the emulator
 */
extern void wii_vb_free(); //TODO

/**
 * Loads the specified game
 *
 * game     The name of the game
 * return   1 if the load is successful, 0 if it fails
 */
extern int wii_vb_load_game( char* game );

/*
 * The emulation loop
 *
 * resume   Whether we are resuming
 */
extern void wii_vb_emu_loop( bool resume );

#endif