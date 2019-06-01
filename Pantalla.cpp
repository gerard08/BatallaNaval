#pragma once
#include "Pantalla.h"
#include <fstream>

void inicialitza(int a[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			a[i][j] = 0;
		}
	}
}

Pantalla::Pantalla()
{
	aux = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_taulerPropi[i][j] = m_taulerContrari[i][j] = 0;
		}
	}
	m_blanc.create("data/blanc.png");
	m_load.create("data/buttonLoad.png");
	m_play.create("data/buttonPlay.png");
	m_vaixell.create("data/vaixell.png");
	m_aigua.create("data/aigua.png");
	m_tocat.create("data/tocat.png");
	m_enfonsat.create("data/enfonsat.png");
	inicialitza(m_taulerPropi);
	inicialitza(m_taulerContrari);
	m_tauler.create("data/caselles.png");
	m_interrogant.create("data/what.png");
	m_nou.create("data/+.png");
	m_black.create("data/black.png");
	m_save.create("data/save.png");
	m_buit.create("data/buit.png");
	m_start.create("data/play.png");
	m_u.create("data/1.png");
	m_dos.create("data/2.png");
	m_tres.create("data/3.png");
	m_cuatre.create("data/4.png");
	m_cinc.create("data/5.png");
	m_sis.create("data/6.png");
	m_set.create("data/7.png");
	m_vuit.create("data/8.png");
	m_nine.create("data/9.png");
	m_deu.create("data/10.png");
}


void Pantalla::visualitza()
{
	
	m_tauler.draw(0, 0);
	m_tauler.draw(520, 0);
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			switch (m_taulerPropi[i][j])
			{
			case 0: m_aigua.draw(i * 52, j * 52); break;
			case 1: m_vaixell.draw(i * 52, j * 52); break;
			case 2: m_tocat.draw(i * 52, j * 52); break;
			case 3: m_enfonsat.draw(i * 52, j * 52); break;
			default: m_buit.draw(i * 52, j * 52); break;
			}
		}
	}
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			switch (m_taulerContrari[i][j])
			{
			case 0: m_interrogant.draw(52+520 + i * 52, j * 52); break;
			case 1: m_vaixell.draw(52+520 + i * 52, j * 52); break;
			case 2: m_tocat.draw(52+520 + i * 52, j * 52); break;
			case 3: m_enfonsat.draw(52+520 + i * 52, j * 52); break;
			default: m_aigua.draw(52+520 + i * 52, j * 52); break;
			}
		}
	}
	for(int a=0;a<10;a++)
		m_black.draw(520, a*52);
	m_nou.draw(520, 0);
	m_save.draw(520, 52);
	if (aux)m_vaixells = 10;
	switch (m_vaixells)
	{
	case 0:m_deu.draw(520, 520 - 52); break;
	case 1:m_nine.draw(520, 520 - 52); break;
	case 2:m_vuit.draw(520, 520 - 52); break;
	case 3:m_set.draw(520, 520 - 52); break;
	case 4:m_sis.draw(520, 520 - 52); break;
	case 5:m_cinc.draw(520, 520 - 52); break;
	case 6:m_cuatre.draw(520, 520 - 52); break;
	case 7:m_tres.draw(520, 520 - 52); break;
	case 8:m_dos.draw(520, 520 - 52); break;
	case 9:m_u.draw(520, 520 - 52); break;
	case 10:m_start.draw(520, 520 - 52); break;
	}
	

}



void Pantalla::seleccioInici(bool &passat)
{
	#define BTNX 
	m_blanc.draw(0, 0);
	m_load.draw(80, 156);
	m_play.draw((250 * 2)+52+95, 156);

	if (Mouse_getButLeft())

	{
		int x, y;
		x = Mouse_getX();

		y = Mouse_getY();

		//Llegim el mouse i si les coordenades clicades són les del
		//botó de load executem l'odre de càrrega
		if (x > 80 + 25 && x < 80 + 25 + 304)
		{
			if (y > 156+20 && y < 156 + 208-40)
			{
				//insereix tot
				string dir1;
				m_blanc.~Sprite();
				m_load.~Sprite();
				m_play.~Sprite();
				passat = true;
				m_carrego = true;
			}
		}
		//Llegim el mouse i si les coordenades clicades són les del
		//botó de play executem l'odre de càrrega
		int tamanyBtn = (250 * 2) + 52 + 95;
		if (x > tamanyBtn + 25 && x < tamanyBtn + 25 + 304)
		{
			if (y > 156 + 20 && y < 156 + 208 - 40)
			{
				cout << "play" << endl;
				m_blanc.~Sprite();
				m_load.~Sprite();
				m_play.~Sprite();
				passat = true;
				//visualitza();
			}
		}
	}
}

void Pantalla::setPosicioPropi(int fila, int columna, int estat)
{
	m_taulerPropi[fila][columna] = estat;
}

void Pantalla::setPosicioContrari(int fila, int columna, int estat)
{
	m_taulerContrari[fila][columna] = estat;

}


void Pantalla::setTauler(bool usuari, int fila, int columna, int valor)
{
	if (usuari == true)
		m_taulerPropi[fila][columna] = valor;
	else
		m_taulerContrari[fila][columna] = valor;
}

int Pantalla::getTauler(bool usuari, int fila, int columna)
{
	if (usuari == true)
		return m_taulerPropi[fila][columna];//peta
	else
		return m_taulerContrari[fila][columna];
}
