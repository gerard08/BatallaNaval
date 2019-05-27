#include "libreria.h"
#include "keyboard.h"
#include "debug.h"

struct T_KEYBOARD g_Keyboard ;


int Keyboard_GetKeyCnt(int cual)
{
#ifndef __NOT_GRAPHICS
  return(g_Keyboard.cnt[SDL_GetScancodeFromKey(cual)]) ;
#else
	return 0;
#endif
}

int Keyboard_GetKeyTrg(int cual)
{
#ifndef __NOT_GRAPHICS
  return(g_Keyboard.trg[SDL_GetScancodeFromKey(cual)]) ;
#else
	return 0;
#endif
}

void Keyboard_ProcessKeyDown(int tecla)
{
#ifndef __NOT_GRAPHICS
	g_Keyboard.trg[SDL_GetScancodeFromKey(tecla)] = true;
  g_Keyboard.cnt[SDL_GetScancodeFromKey(tecla)] = true;
#endif
}

void Keyboard_ProcessKeyUp(int tecla)
{
#ifndef __NOT_GRAPHICS
  g_Keyboard.cnt[SDL_GetScancodeFromKey(tecla)] = false;
#endif
}

void Keyboard_Init()
{
#ifndef __NOT_GRAPHICS
  memset(&g_Keyboard, 0, sizeof(struct T_KEYBOARD)) ;
#endif
}

void Keyboard_Tick()
{
#ifndef __NOT_GRAPHICS
  memset(g_Keyboard.trg, 0, sizeof(int) * NUM_KEYBOARD_KEY_CODES) ;
#endif
}

