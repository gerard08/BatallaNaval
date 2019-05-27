#include "Vaixell.h"

Vaixell::Vaixell()
{
	m_fila=0;
	m_columna=0;
	m_direccio=0;
	m_nCaselles=0;
	m_nCasellesVives=0;
	m_estat = nullptr;
}

Vaixell::Vaixell(int fila, int columna, int direccio, int nCaselles)
{
	m_fila = fila;
	m_columna = columna;
	m_direccio = direccio;
	m_nCaselles = m_nCasellesVives = nCaselles;
	m_estat = new bool[nCaselles];

	for (int i = 0; i < nCaselles; i++)
		m_estat[i] = true;

}

Vaixell::~Vaixell()
{
	//if(m_estat!=nullptr)
		//delete[] m_estat;
}

Vaixell::Vaixell(const Vaixell& v)
{
	m_fila = v.m_fila;
	m_columna = v.m_columna;
	m_direccio = v.m_direccio;
	m_nCaselles = v.m_nCaselles;
	m_nCasellesVives = v.m_nCasellesVives;
	if (v.m_estat != nullptr)
	{
		m_estat = new bool[m_nCaselles];
		for (int i = 0; i < m_nCaselles; i++)
			m_estat[i] = v.m_estat[i];
	}
	else
		m_estat = nullptr;

}
Vaixell& Vaixell::operator=(const Vaixell& v)
{
	if (this != &v)
	{
		m_fila = v.m_fila;
		m_columna = v.m_columna;
		m_direccio = v.m_direccio;
		m_nCaselles = v.m_nCaselles;
		m_nCasellesVives = v.m_nCasellesVives;
		if (m_estat != nullptr)
		//	delete[] m_estat;
		if (v.m_estat != nullptr)
		{
			m_estat = new bool[m_nCaselles];
			for (int i = 0; i < m_nCaselles; i++)
				m_estat[i] = v.m_estat[i];
		}
		else
			m_estat = nullptr;
	}
	return *this;
}



void Vaixell::setNCaselles(int nCaselles)
{
	m_nCaselles = m_nCasellesVives = nCaselles;
	if (m_estat != nullptr)
		delete[] m_estat;
	m_estat = new bool[nCaselles];
	for (int i = 0; i < nCaselles; i++)
		m_estat[i] = true;
}