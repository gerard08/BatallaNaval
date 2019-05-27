#pragma once
#include "Vaixell.h"
const int N_FILES = 10;
const int N_COLUMNES = 10;
class Jugador
{
public:
	Jugador();
	Jugador(bool tipus) { m_tipusJugador = tipus; };
	//~Jugador();
	void setTipus(bool tipus) { m_tipusJugador = tipus; };
	void afegeixVaixell(int fila, int columna, int direccio, int nCaselles);
	int getNVaixellsVius();
	Vaixell getVaixell(int posicio) { return m_llistaVaixells[posicio]; };
	void setVaixell(int posicio, Vaixell vaixell) { m_llistaVaixells[posicio] = vaixell; };
	void setnVaixellsVius(int n) { m_nVaixellsVius = n; };
	void copiaVaixell(Vaixell copia);
	void actualitza();
private:
	static const int N_VAIXELLS = 10;
	Vaixell m_llistaVaixells[N_VAIXELLS];
	int m_nVaixellsVius;
	bool m_tipusJugador;
	int m_taulerContrari[N_FILES][N_COLUMNES];
};