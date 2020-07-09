#include "3ds_vb_main.h"

void wii_start_emulation( char *romfile, const char *savefile, bool reset, bool resume )
{
	bool succeeded = true;

	printf("Loading game %s\n", romfile);

	succeeded = ( wii_vb_load_game( romfile ) != 0 );

	if(succeeded)
	{
		printf("Loaded game!\n");
	// Start the emulator loop
      wii_vb_emu_loop( resume );
	}
	else
	{
		printf("Failed to load game from %s\n", romfile);
	}

}