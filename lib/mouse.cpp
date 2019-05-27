#include "video.h"
#include "mouse.h"
#include "libreria.h"


// Variable que guarda el estado del rat?
struct T_MOUSE g_Mouse ;


// ------------------------------------------------------------------------------------------------
// Esta funci? no est?pensada para usarse directamente. Avisa de que se acaba de pulsar un 
// bot? del rat?
//
void Mouse_ProcessButtonDown(int boton)
{
#ifndef __NOT_GRAPHICS
  g_Mouse.trg[boton] = true;
  g_Mouse.cnt[boton] = true;
#endif
}


// ------------------------------------------------------------------------------------------------
// Esta funci? no est?pensada para usarse directamente. Avisa de que se acaba de soltar un 
// bot? del rat?
//
void Mouse_ProcessButtonUp(int boton)
{
#ifndef __NOT_GRAPHICS
  g_Mouse.cnt[boton] = false;
#endif
}




// ------------------------------------------------------------------------------------------------
// Esta funci? procesa los datos de haber movido la rueda del rat?
//
void Mouse_ProcessWheel(int wheelx, int wheely)
{
#ifndef __NOT_GRAPHICS
  if(wheely > 0) 
  {
    g_Mouse.bWheelUp = true;
  } else {
    if(wheely < 0) 
    {
      g_Mouse.bWheelDown = true;
    }
  }

  if(wheelx < 0) 
  {  
    g_Mouse.bWheelLeft = true;
  } else {
    if(wheelx > 0) 
    {  
      g_Mouse.bWheelRight = true;
    }
  }
#endif
}

// Inicializa la estructura de datos de rat? para poderla usar
void Mouse_Init()
{
#ifndef __NOT_GRAPHICS
  memset(&g_Mouse, 0, sizeof(struct T_MOUSE)) ;
#endif
}

// Procesa los datos que tenemos del rat? para que luego podamos leer algo con sentido
void Mouse_Tick()
{
#ifndef __NOT_GRAPHICS
  Uint8 button_bitmask ;
  int var_boton ;

  // Leemos las coordenadas, y de paso la m?cara de botones pulsados

  g_Mouse.last_x = g_Mouse.x ;
  g_Mouse.last_y = g_Mouse.y ;

  button_bitmask = SDL_GetMouseState(&g_Mouse.x, &g_Mouse.y) ;

  g_Mouse.offset_x = g_Mouse.x - g_Mouse.last_x ;
  g_Mouse.offset_y = g_Mouse.y - g_Mouse.last_y ;

  // Hay que vigilar que el rat? est?dentro de la pantalla, si no lo est?lo ignoramos

  // Hacer la comprobaci? con (unsigned)pos > tam ?

  if(g_Mouse.x >= g_Video.resx) g_Mouse.x = g_Video.resx - 1 ;
  if(g_Mouse.x < 0) g_Mouse.x = 0 ;
  
  if(g_Mouse.y >= g_Video.resy) g_Mouse.y = g_Video.resy - 1 ;
  if(g_Mouse.y < 0) g_Mouse.y = 0 ;

  for(var_boton = BUTTON_1; var_boton < MAX_NUM_POINTER_BUTTONS; var_boton++) {

    if(button_bitmask & SDL_BUTTON(var_boton)) {
    
      Mouse_ProcessButtonDown(var_boton) ;
    }
  }

  // Borramos los triggers

  memset(g_Mouse.trg, 0, sizeof(int) * MAX_NUM_POINTER_BUTTONS) ;
  
  g_Mouse.bWheelUp = false;
  g_Mouse.bWheelDown = false;

  g_Mouse.bWheelLeft = false;
  g_Mouse.bWheelRight = false;
#endif
}

int Mouse_getX()
{
#ifndef __NOT_GRAPHICS
	return g_Mouse.x;
#else
	return 0;
#endif
}

int Mouse_getY()
{
#ifndef __NOT_GRAPHICS
	return g_Mouse.y;
#else
	return 0;
#endif
}

int Mouse_getButLeft()
{
#ifndef __NOT_GRAPHICS
	return g_Mouse.trg[BUTTON_1]; 
#else
		return 0;
#endif
}