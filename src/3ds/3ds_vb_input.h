#ifndef N3DS_VB_INPUT_H
#define N3DS_VB_INPUT_H

#include <3ds.h>

extern u16 wii_paddata;

extern void wii_vb_update_controls();

#define VB_KEY_A      0x0004
#define VB_KEY_B      0x0008
#define VB_KEY_R      0x0010
#define VB_KEY_L      0x0020
#define VB_KEY_START  0x1000
#define VB_KEY_SELECT 0x2000
#define VB_L_RIGHT    0x0100
#define VB_L_LEFT     0x0200
#define VB_L_DOWN     0x0400
#define VB_L_UP       0x0800
#define VB_R_RIGHT    0x0080
#define VB_R_LEFT     0x4000
#define VB_R_DOWN     0x8000
#define VB_R_UP       0x0040

#endif // N3DS_VB_INPUT_H