#pragma once
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED

#include "joc.h" //Aquest inclou llibreria grafica


//Arguments necesaris per poder incloure la llibreria i que trobi el main
int main(int argc, char* argv[])
{
	bool modeGrafic = false;
#ifndef __NOT_GRAPHICS
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	modeGrafic = true;
	///////////////////////////////////////////////////////////////////////////
#endif

	joc(modeGrafic);

#ifndef __NOT_GRAPHICS
	//Instruccio necesaria per poder incloure la llibreria i que trobi el main
	SDL_Quit();
	///////////////////////////////////////////////////////////////////////////
#endif
	return 0;
}

