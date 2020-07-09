#ifndef N3DS_VB_EMULATION_H
#define N3DS_VB_EMULATION_H

/*
 * Starts the emulator for the specified rom file.
 *
 * romfile  The rom file to run in the emulator
 * savefile The name of the save file to load. If this value is NULL, no save
 *          is explicitly loaded (auto-load may occur). If the value is "", 
 *          no save is loaded and auto-load is ignored (used for reset).
 * reset    Whether we are resetting the current game
 * resume   Whether we are resuming the current game
 */
extern void wii_start_emulation( 
  char *romfile, const char *savefile = NULL, bool reset = false, bool resume = false );

#endif // N3DS_VB_EMULATION_H