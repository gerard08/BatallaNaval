#include "Jugador.h"

Jugador::Jugador()
{
	m_nVaixellsVius = 0;
	for (int i = 0; i < 10; i++)
	{
		m_llistaVaixells[i].setFila(0);
		m_llistaVaixells[i].setColumna(0);
		m_llistaVaixells[i].setDireccio(0);
		m_llistaVaixells[i].setNCaselles(0);
		m_llistaVaixells[i].setNCasellesvives(0);
	}
}

void Jugador::afegeixVaixell(int fila, int columna, int direccio, int nCaselles)
{
	if (m_nVaixellsVius < N_VAIXELLS)
	{
		m_llistaVaixells[m_nVaixellsVius].setFila(fila);
		m_llistaVaixells[m_nVaixellsVius].setColumna(columna);
		m_llistaVaixells[m_nVaixellsVius].setDireccio(direccio);
		m_llistaVaixells[m_nVaixellsVius].setNCaselles(nCaselles);
		m_llistaVaixells[m_nVaixellsVius].setNCasellesvives(nCaselles);
		m_nVaixellsVius++;
	}
}

int Jugador::getNVaixellsVius()
{
	int n = 0;
	for (int i = 0; i < N_VAIXELLS; i++)
	{
		if (m_llistaVaixells[i].EsViu())n++;
	}
	return n;
}

void Jugador::copiaVaixell(Vaixell copia)
{
	m_llistaVaixells[m_nVaixellsVius].setFila(copia.getFila());
	m_llistaVaixells[m_nVaixellsVius].setColumna(copia.getColumna());
	m_llistaVaixells[m_nVaixellsVius].setDireccio(copia.getDireccio());
	m_llistaVaixells[m_nVaixellsVius].setNCaselles(copia.getNcaselles());
	m_llistaVaixells[m_nVaixellsVius].setNCasellesvives(copia.getNCasellesVives());
	m_nVaixellsVius++;
}

void Jugador::actualitza()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_llistaVaixells[i].EsViu() == false)m_nVaixellsVius--;
	}
}