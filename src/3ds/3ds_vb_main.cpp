
#include "main.h"
#include "sound.h"

#include "3ds_vb.h"
#include "3ds_sdl.h"

// Mednafen external references
extern volatile Uint32 MainThreadID;
extern MDFNSetting DriverSettings[]; 
extern int DriverSettingsSize;
extern std::vector <MDFNSetting> NeoDriverSettings;
extern char *DrBaseDirectory;
extern volatile MDFN_Surface *VTReady;
extern volatile MDFN_Rect *VTLWReady;
extern volatile MDFN_Rect *VTDRReady;
extern MDFN_Rect VTDisplayRects[2];
extern volatile MDFN_Surface *VTBuffer[2];
extern MDFN_Rect *VTLineWidths[2];
extern SDL_Surface *screen;
extern volatile int NeedVideoChange;

namespace MDFN_IEN_VB
{
  extern void VIP_SetParallaxDisable(bool disabled);
  extern void VIP_SetAnaglyphColors(uint32 lcolor, uint32 rcolor);
  extern void VIP_Set3DMode(uint32 mode, bool reverse, uint32 prescale, uint32 sbs_separation);

  extern int vb_skip_sum;
  extern int vb_skip_frame;
}

extern int LoadGame(const char *force_module, const char *path);
extern int GameLoop(void *arg);
extern char *GetBaseDirectory(void);
extern void KillVideo(void);
extern void FPS_Init(void);
extern void MakeMednafenArgsStruct(void);
extern bool CreateDirs(void);
extern void MakeVideoSettings(std::vector <MDFNSetting> &settings);
extern void MakeInputSettings(std::vector <MDFNSetting> &settings);
extern void DeleteInternalArgs(void);
extern void KillInputSettings(void);
extern void CalcFramerates(char *virtfps, char *drawnfps, char *blitfps, size_t maxlen);

/*
 * Initializes the emulator
 */
void wii_vb_init()
{
  std::vector<MDFNGI *> ExternalSystems;
  MainThreadID = SDL_ThreadID();

  DrBaseDirectory=GetBaseDirectory();

  MDFNI_printf(_("Starting Mednafen %s\n"), MEDNAFEN_VERSION);
  MDFN_indent(1);
  MDFN_printf(_("Base directory: %s\n"), DrBaseDirectory);

  // Look for external emulation modules here.
  if(!MDFNI_InitializeModules(ExternalSystems))
  {
    MDFN_PrintError( "Unable to initialize external modules" );
    exit( 0 );
  }

  for(unsigned int x = 0; x < DriverSettingsSize / sizeof(MDFNSetting); x++)
    NeoDriverSettings.push_back(DriverSettings[x]);

  MakeVideoSettings(NeoDriverSettings);
  MakeInputSettings(NeoDriverSettings);

  if(!(MDFNI_Initialize(DrBaseDirectory, NeoDriverSettings))) 
  {
    MDFN_PrintError( "Error during initialization" );
    exit( 0 );
  }

  MakeMednafenArgsStruct();

  VTReady = NULL;
  VTDRReady = NULL;
  VTLWReady = NULL;

  MDFN_PixelFormat nf;
#if BPP == 8
  nf.bpp = 8;
#elif BPP == 16
  nf.bpp = 16;
#else
  nf.bpp = 32;
#endif
  nf.colorspace = MDFN_COLORSPACE_RGB;

  VTBuffer[0] = new MDFN_Surface(NULL, VB_WIDTH, VB_HEIGHT, VB_WIDTH, nf);
  //VTBuffer[1] = new MDFN_Surface(NULL, VB_WIDTH, VB_HEIGHT, VB_WIDTH, nf);
  VTBuffer[1] = VTBuffer[0];
  VTLineWidths[0] = (MDFN_Rect *)calloc(VB_HEIGHT, sizeof(MDFN_Rect));
  //VTLineWidths[1] = (MDFN_Rect *)calloc(VB_HEIGHT, sizeof(MDFN_Rect));
  VTLineWidths[1] = VTLineWidths[0];

  FPS_Init();

  KillVideo();

  // Set the screen to our back surface
  screen = back_surface;  
}

/*
 * Free resources (closes) the emulator
 */
void wii_vb_free()
{
  CloseGame();

  if(VTBuffer[0])
  {
    delete VTBuffer[0];
    VTBuffer[0] = NULL;
  }

  if(VTLineWidths[0])
  {
    free(VTLineWidths[0]);
    VTLineWidths[0] = NULL;
  }

  MDFNI_Kill();
  DeleteInternalArgs();
  KillInputSettings();
}

int wii_vb_load_game(char* game)
{
	return LoadGame(NULL, game);
}

void wii_vb_emu_loop( bool resume )
{
    // Reset frame skip information
    MDFN_IEN_VB::vb_skip_frame = 0;
#ifdef BOUND_HIGH_HACK
    // This is an extremely lame hack that allows for "Bound High!" to work
    // correctly with frame skipping. 
    MDFN_IEN_VB::vb_skip_sum = wii_get_render_rate();
#else
    MDFN_IEN_VB::vb_skip_sum = 0;
#endif

  //wii_vb_db_apply_button_map( &wii_vb_db_entry );

 for(int i = 0; i < 2; i++)
    ((MDFN_Surface *)VTBuffer[i])->Fill(0, 0, 0, 0);

 // const Vb3dMode mode = wii_get_vb_mode();
 /* if( wii_is_custom_mode( &mode ) )
  {
    MDFN_IEN_VB::VIP_SetParallaxDisable( !wii_custom_colors_parallax );
    MDFN_IEN_VB::VIP_SetAnaglyphColors( 
      Util_rgbatovalue( &wii_custom_colors[0], FALSE ),      
      Util_rgbatovalue( &wii_custom_colors[1], FALSE )
    );
  }
  else
  {
    MDFN_IEN_VB::VIP_SetParallaxDisable( !mode.isParallax );
    MDFN_IEN_VB::VIP_SetAnaglyphColors( mode.lColor, mode.rColor );
  }
  //MDFN_IEN_VB::VIP_Set3DMode( 0, false, 1, 0 );

  wii_sdl_black_back_surface();
  WII_SetRenderCallback( &gxrender_callback );  
  WII_ChangeSquare( wii_screen_x, wii_screen_y, 0, 0 );  
  WII_VideoStart();    */
 // ClearSound();
 // PauseSound( 0 );

 //MDFN_IEN_VB::VIP_Set3DMode(2, false, 1, 0);

  GameThreadRun = 1;
  NeedVideoChange = 0;

  printf("Running game loop\n");
  GameLoop( NULL );

 // PauseSound( 1 );
 // WII_VideoStop();     
}