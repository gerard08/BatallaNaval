#pragma once

///////////////////////////////////////////////////////////////////////////
//Llibreria grafica
#include "lib/libreria.h"
///////////////////////////////////////////////////////////////////////////

//========================================================================
// Mida Pantalla
const int MIDA_X = 52+520*2;
const int MIDA_Y = 520;

//========================================================================
// Inici del tauler respecte la cantonada superior esquerre
const int INI_PANTALLA_X = 0;
const int INI_PANTALLA_Y = 0;

//========================================================================
// Fi del tauler respecte la cantonada inferior dreta
const int FI_PANTALLA_X = 520;
const int FI_PANTALLA_Y = 520;

// Mida d'una casella del tauler
const int MIDA_CASELLA = 52;

void joc(bool mode);

/*----- END --------------*/