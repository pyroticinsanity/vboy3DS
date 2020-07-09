
#include <3ds.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "3ds_main.h"
#include "3ds_vb_emulation.h"

void waitForExit()
{
	printf("Press START to Exit\n");
	while (aptMainLoop())
	{
		svcSleepThread(1);
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

	}
}

static void init_app()
{
	wii_handle_init();
}


//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);

	atexit(&waitForExit);

	printf("Initializing app\n");

	init_app();

	printf("Starting emulation\n");

	wii_start_emulation("/vb/wario.vb");
	// Main loop

	wii_handle_free_resources();
	// Deinit libs
	gfxExit();
	return 0;
}


