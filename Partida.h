#pragma once
#include "Pantalla.h"
#include "Jugador.h"
#include <string.h>
#include <iostream>
#include "Jugador.h"
#include "Anterior.h"
#include "llista.h"
#define TAMANY_MINIM 10
using namespace std;
class Partida
{
public:
	Partida();
	~Partida();
	void visualitza(bool &passat);
	bool getTf() { return tf; };
	void setTf(bool set) { tf = set; };
	bool ataca(const bool& tauler, const int& fila, const int& columna);
	void IniciaEnemic();
	void atac(int u_x, int u_y);
	void redimensiona(int dim);
	void amplia(int dim);
	void pensa(int& x, int& y);
	bool repetit(int x, int y);
	void comprovaxoc(bool tauler, int x, int y);
	bool getAcabat(bool &guanyador);
	void setAcabat(bool estat) { acabat = estat; };
	bool getPreparacio() { return preparacio; };
	void setPreparacio(bool ready) { preparacio = ready; };
	void afegeixVaixell(int x, int y);
	void setAfegint(bool tf) { afegint = tf; };
	void permetComencar(bool permis);
	int getnVaixells() { return m_nVaixells; };
	//void anima() { m_tauler.anima(); };
	void guarda();
	void carrega();
	bool getCarrego() { return m_tauler.getCarrego(); };
	void setCarrego(bool aux) { m_tauler.setCarrego(aux); };
private:
	Pantalla m_tauler;
	Jugador m_jugador1;
	Jugador m_enemic;
	int m_torn;
	bool tf;
	Anterior* anterior;
	int nmax;
	int m_nElements;
	bool preparacio;
	bool acabat;
	Llista* llista;
	Llista* afegeix;
	int m_nElements_temp;
	bool afegint;
	int m_nVaixells;
	int m_MaxElements;
};
