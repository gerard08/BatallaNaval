#pragma once


class Vaixell
{
public:
	Vaixell();
	Vaixell(int fila, int columna, int direccio, int nCaselles);
	~Vaixell();
	Vaixell(const Vaixell& v);//constructor de còpia
	void setFila(int fila) { m_fila = fila; }
	void setColumna(int columna) { m_columna = columna; }
	void setDireccio(int direccio) { m_direccio = direccio; }
	void setNCaselles(int nCaselles);
	int getFila() const { return m_fila; }
	int getColumna() const { return m_columna; }
	int getDireccio() const { return m_direccio; }
	int getNCasellesVives() const { return m_nCasellesVives; }
	Vaixell& operator=(const Vaixell& v);
	int getNcaselles() { return m_nCaselles; };
	void setNCasellesvives(int num) { m_nCasellesVives = num; };
	int getDireccio() { return m_direccio; };
	void tocat() { m_nCasellesVives--; };
	bool EsViu() { if (m_nCasellesVives != 0)return true; else return false; }
private:
	int m_fila;
	int m_columna;
	int m_direccio;
//	bool* m_estat;
	int m_nCaselles;
	int m_nCasellesVives;
};
