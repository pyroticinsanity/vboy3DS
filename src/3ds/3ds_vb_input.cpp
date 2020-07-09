
#include <stdio.h>

#include "3ds_vb_input.h"

u16 wii_paddata = 0;

void updateKey(u16 key, u16* result)
{
	printf("Key pressed: %x\n", key);
	*result |= key;
}

void wii_vb_update_controls()
{
	hidScanInput();
	u32 hDown = hidKeysHeld();
	u16 result = 0;

	if(hDown & KEY_START) updateKey(VB_KEY_START, &result);

	if(hDown & KEY_SELECT) updateKey(VB_KEY_SELECT, &result);

	if(hDown & KEY_A) updateKey(VB_KEY_A, &result);

	if(hDown & KEY_B) updateKey(VB_KEY_B, &result);
	if(hDown & KEY_L) updateKey(VB_KEY_L, &result);
	if(hDown & KEY_R) updateKey(VB_KEY_R, &result);

	if(hDown & KEY_DLEFT) updateKey(VB_L_LEFT, &result);
	if(hDown & KEY_DRIGHT) updateKey(VB_L_RIGHT, &result);
	if(hDown & KEY_DUP) updateKey(VB_L_UP, &result);
	if(hDown & KEY_DDOWN) updateKey(VB_L_DOWN, &result);

	if(hDown & KEY_CSTICK_LEFT) updateKey(VB_R_LEFT, &result);
	if(hDown & KEY_CSTICK_RIGHT) updateKey(VB_R_RIGHT, &result);
	if(hDown & KEY_CSTICK_UP) updateKey(VB_R_UP, &result);
	if(hDown & KEY_CSTICK_DOWN) updateKey(VB_R_DOWN, &result);

	// Always have to do this...
	result |= 0x0002;

	wii_paddata = result;
}