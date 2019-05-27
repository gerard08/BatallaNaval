#pragma once
#include "joc.h"
#include "Jugador.h"
#include <iostream>
#include <string.h>
using namespace std;
class Pantalla
{
public:
	Pantalla();
	//~Pantalla();
	void visualitza();
	void seleccioInici(bool &passat);
	void setPosicioPropi(int fila, int columna, int estat);
	void setPosicioContrari(int fila, int columna, int estat);
	int getPosicioPropi(int fila, int columna) { return m_taulerPropi[fila-1][columna-1]; };
	int getPosicioContrari(int fila, int columna) { return m_taulerContrari[fila-1][columna-1]; };
	void setTauler(bool usuari, int fila, int columna, int valor);
	int getTauler(bool enemic, int fila, int columna);
	bool getCarrego() { return m_carrego; };
	void setCarrego(bool aux) { m_carrego=aux; };
	void setVaixells(int n) { m_vaixells = n; };
	void setAux(bool tf) { aux = tf; };

private:
	int m_taulerPropi[N_FILES][N_COLUMNES];
	int m_taulerContrari[N_FILES][N_COLUMNES];
	bool seleccio=0;
	int m_vaixells;
	bool m_carrego;
	bool aux;
	Sprite m_tauler;
	Sprite m_vaixell;
	Sprite m_aigua;
	Sprite m_tocat;
	Sprite m_enfonsat;
	Sprite m_blanc;
	Sprite m_load;
	Sprite m_play;
	Sprite m_interrogant;
	Sprite m_nou ;
	Sprite m_black;
	Sprite m_save;
	Sprite m_buit;
	Sprite m_start;
	Sprite m_u;
	Sprite m_dos;
	Sprite m_tres;
	Sprite m_cuatre;
	Sprite m_cinc;
	Sprite m_sis;
	Sprite m_set;
	Sprite m_vuit;
	Sprite m_nine;
	Sprite m_deu;
};