#include "Partida.h"
#include <fstream>
//#include <cstdlib> 
#include <ctime> 
//constructor i destructor
Partida::Partida()
{
	m_torn = 0;
	anterior = nullptr;
	afegeix = nullptr;
	nmax = 0;
	m_nElements = 0;
	m_nElements_temp = 0;
	m_MaxElements = 10;
	m_tauler.setVaixells(0);
}
Partida::~Partida()
{
	delete[] anterior;
	anterior = nullptr;
}
//inicialització de partida
void Partida::visualitza(bool& passat)
{
	if (!passat)
	{
		m_tauler.seleccioInici(passat);
		
	}
	else
	{
		m_tauler.visualitza();
	}
}
void Partida::IniciaEnemic()
{
	int l = 0;
	int repeticions = 0;
	for (int i = 0; i < 10; i++)
	{
		if (l <= (m_MaxElements) / 4)
		{
			m_MaxElements *= 2;
			amplia(m_MaxElements);
		}
		int fila, columna, direccio, ncaselles;
		//direccio
		int temp  = ((double)rand() / (1));
		if (temp %2 == 0)direccio = 1;
		else direccio = 0;
		//ncaselles
		ncaselles = 2 + rand() % (5 - 1);
		bool xoc=false;
		bool repetit_;
		do
		{
			repetit_ = false;
			//fila
			if (direccio == 0)fila = 1 + (rand() % (11 - 1 ));
			else
			{
				fila = 1 + rand() % ((11 - ncaselles) - 1 );
			}		
			//columna
			if (direccio == 1)columna = 1 + (rand() % (11 - 1 ));
			else
			{
				columna = 1 + rand() % ((11 - ncaselles) - 1 );
			}

			xoc = false;
			int j = 0;
			while (!xoc && j < ncaselles)
			{
				if (direccio == 0)
				{
					if (m_tauler.getPosicioContrari(fila, columna + j))xoc = true;
					if (repetit(fila, columna))xoc = true;
					if (fila + ncaselles >= 10)xoc = true;
					if (m_tauler.getPosicioContrari(fila, columna - 1) == 1)xoc = true;
					if (m_tauler.getPosicioContrari(fila-1, columna) == 1)xoc = true;

				}
				else
				{
					int temp=m_tauler.getPosicioContrari(fila - 1 + j, columna - 1);
					if (repetit(fila, columna))xoc = true;
					if (temp == 1)xoc = true;
					if (columna + ncaselles >= 10)xoc = true;
					if (m_tauler.getPosicioContrari(fila, columna - 1) == 1)xoc = true;
					if (m_tauler.getPosicioContrari(fila - 1, columna) == 1)xoc = true;
				}
				j++;
			}
			if (i != 0)
			{
				for (int k = 0; k < l; k++)
				{
					for (int casella=0; casella < ncaselles; casella++)
					{
						if (llista[k].getX() == fila+casella && llista[k].getY() == columna+casella)repetit_ = true;
					}
				}

			}
			repeticions++;
			if(repeticions==10)	srand((unsigned)time(0));
		} while (xoc == true || repetit_==true);
		
	
		//posa les caselles que falten al tauler
		for (int i = 0; i < ncaselles; i++)
		{
			if (direccio == 0) m_tauler.setPosicioContrari(fila - 1 + i, columna - 1, 1);
			else m_tauler.setPosicioContrari(fila - 1, columna - 1 + i, 1);
		}
		if (!repetit_)
		{
				llista[l].setX(fila);
				llista[l].setY(columna);
				l++;
		}
		m_enemic.afegeixVaixell(fila, columna, direccio, ncaselles);
		//cout << fila << " " << columna << " " << direccio << " " << ncaselles << endl;
		repeticions = 0;
	}
		delete[] llista;
		llista = nullptr;
	
}
//atacs
bool Partida::ataca(const bool& tauler, const int& fila, const int& columna)
{
	bool tocat = false;
	if (m_tauler.getTauler(tauler ,fila, columna) == 1)
	{
		m_tauler.setTauler(tauler, fila, columna, 2);
		tocat = true;
	}
	else if(m_tauler.getTauler(tauler, fila, columna)!=2 && m_tauler.getTauler(tauler, fila, columna)!=3)m_tauler.setTauler(tauler, fila, columna, 40);
	return tocat;
}	
void Partida::atac(int u_x, int u_y)
{
	int x, y;
	bool tocat;
	if (m_torn % 2==0)
	{
		cout << "torn jugador < " << m_torn << " >" << endl;
		tocat=ataca(0, u_x, u_y);
		if (tocat)comprovaxoc(0, u_x, u_y);
		else m_torn++;
	}
	else
	{
		cout << "torn enemic < " << m_torn << " >" << endl;
		if (nmax == 0)redimensiona(TAMANY_MINIM);
		else if (m_nElements > nmax / 4)redimensiona(nmax * 2);
		pensa(x, y);
		tocat = ataca(1, x, y);
		anterior[m_nElements-1].setTocat(tocat);
		if (tocat)comprovaxoc(1, x, y);
		else m_torn+=1;
	}
}
void Partida::redimensiona(int dim)
{
	Anterior* aux;
	aux = new Anterior[dim];

	for (int i = 0; i < m_nElements; i++)
	{
		aux[i] = anterior[i];
	}

	if (anterior != nullptr)
		delete[] anterior;
	anterior = aux;
	nmax = dim;
	aux = nullptr;
}
void Partida::amplia(int dim)
{
	Llista* aux;
	aux = new Llista[dim];

	for (int i = 0; i < m_nElements; i++)
	{
		aux[i].setX(llista[i].getX());
		aux[i].setY(llista[i].getY());
	}

	if (llista != nullptr)
		delete[] llista;
	llista = aux;
	aux = nullptr;
}
void Partida::pensa(int& x, int& y)
{
	int aux=0;
	do
	{
		x = (0+rand() % (11 - 1));
		y = (0+rand() % (11 - 1));

		if (anterior[m_nElements - 1].getTocat() == true && m_nElements >= 1 && aux==0)
		{
			x = anterior[m_nElements - 1].getX();
			if (anterior[m_nElements - 1].getY() < 10)y = anterior[m_nElements - 1].getY() + 1;
			else y = anterior[m_nElements - 1].getY() - 1;
			if (repetit(x, y))aux = 1;
			else aux = 50;
		}
		if (anterior[m_nElements - 2].getTocat() == true && m_nElements >= 2 && aux<2)
		{
			x = anterior[m_nElements - 2].getX();
			if (anterior[m_nElements - 2].getY() >= 10)y = anterior[m_nElements - 2].getY() - 1;
			else y = anterior[m_nElements - 2].getY() - 1;
			if (repetit(x, y))aux = 2;
			else aux = 50;
		}
		if (anterior[m_nElements - 3].getTocat() == true && m_nElements >= 3 && aux<3)
		{
			if (anterior[m_nElements - 3].getX() >= 10)x = anterior[m_nElements - 3].getX() - 1;
			else x = anterior[m_nElements - 3].getX() + 1;
			y = anterior[m_nElements - 3].getY();
			if (repetit(x, y))aux = 3;
			else aux = 50;
		}
		if (anterior[m_nElements - 4].getTocat() == true && m_nElements >= 4 && aux<4)
		{
			if (anterior[m_nElements - 4].getX() >= 10) x = anterior[m_nElements - 4].getX() - 1;
			else x = anterior[m_nElements - 4].getX() - 1;
			y = anterior[m_nElements - 4].getY();
			if (repetit(x, y))aux = 4;
			else aux = 50;
		}
	
		if (!repetit(x,y))
		{
			anterior[m_nElements].setX(x);
			anterior[m_nElements].setY(y);
		}
		
	} while (repetit(x, y));
	if((m_tauler.getTauler(1, x, y) == 1))
		anterior[m_nElements].setTocat(true);
	m_nElements++;
}
bool Partida::repetit(int x, int y)
{
	int i = 0;
	bool trobat = false;
	while (i < m_nElements && !trobat)
	{
		if (x == anterior[i].getX() && y == anterior[i].getY())trobat = true;
		i++;
	}
	if (x > 9)trobat = true;
	return trobat;
}
//reacció als atacs
void Partida::comprovaxoc(bool enemic, int x, int y)
{
	bool enfonsat = false;
	if (!enemic)
	{
		for (int i = 0; i < 10; i++)
		{
			Vaixell vaixell = m_enemic.getVaixell(i);
			int fila = vaixell.getFila()-1;
			int columna = vaixell.getColumna()-1;
			

			for (int j = 0; j < vaixell.getNcaselles(); j++)
			{
				if (vaixell.getDireccio() == 1)
				{
					if (x == fila && y == columna)
					{
						vaixell.tocat();
						m_enemic.setVaixell(i, vaixell);
					}
					columna++;
				}
				else
				{
					if (x == fila && y == columna)
					{
						vaixell.tocat();
						m_enemic.setVaixell(i, vaixell);
					}
					fila++;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (m_enemic.getVaixell(i).getNCasellesVives() == 0)
				{
					int x, y;
					x = m_enemic.getVaixell(i).getFila()-1;
					y = m_enemic.getVaixell(i).getColumna()-1;
					for (int j = 0; j < m_enemic.getVaixell(i).getNcaselles(); j++)
					{
						if (m_enemic.getVaixell(i).getDireccio() == 1)
							m_tauler.setTauler(0, x, y + j, 3);
						else m_tauler.setTauler(0, x + j, y, 3);
					}
					enfonsat = true;
				}
			}
		}
	}
	if (enemic)
	{
		for (int i_ = 0; i_ < 10; i_++)
		{
			Vaixell vaixell_ = m_jugador1.getVaixell(i_);
			int fila = vaixell_.getFila();
			int columna = vaixell_.getColumna();


			for (int j = 0; j < vaixell_.getNcaselles(); j++)
			{
				if (vaixell_.getDireccio() == 1)
				{
					if (x == fila && y == columna)
					{
						cout<<m_jugador1.getVaixell(i_).getNCasellesVives()<<endl;
						vaixell_.tocat();
						m_jugador1.setVaixell(i_, vaixell_);
						cout << m_jugador1.getVaixell(i_).getNCasellesVives()<<endl;

					}
					columna++;
				}
				else 
				{
					if (x == fila && y == columna)
					{
						vaixell_.tocat();
						m_jugador1.setVaixell(i_, vaixell_);
					}
					fila++;
				}
			}
			for (int i_ = 0; i_ < 10; i_++)
			{
				if (m_jugador1.getVaixell(i_).getNCasellesVives() == 0)
				{
					int x_, y_;
					x_ = m_jugador1.getVaixell(i_).getFila();
					y_ = m_jugador1.getVaixell(i_).getColumna();
					for (int j_ = 0; j_ < m_jugador1.getVaixell(i_).getNcaselles(); j_++)
					{
						if (m_jugador1.getVaixell(i_).getDireccio() == 1)
						{
							m_tauler.setTauler(1, x_, y_ + j_, 3);
						}
						else if(m_jugador1.getVaixell(i_).getDireccio()==0)
						{
							m_tauler.setTauler(1, x_ + j_, y_, 3);
						}
					}
				}
			}
		}
	}
	if (enfonsat)m_jugador1.setnVaixellsVius(m_jugador1.getNVaixellsVius() - 1);

}
bool Partida::getAcabat(bool &guanyador)
{
	int a=0, b = 0;
	if (!preparacio)
	{
		if (m_jugador1.getNVaixellsVius() == 0)
		{
			acabat = true;
			guanyador = true;
		}
		if (m_enemic.getNVaixellsVius()==0)
		{
			acabat = true;
			guanyador = false;
		}
	}
	return acabat;
}
//inicialització del jugador
void Partida::afegeixVaixell(int x, int y)
{
	if (m_nVaixells < 10)
	{

		//mirar totes dades per determinar la posició i la casella inicial.
		if (!afegint)
		{
			if (afegeix != nullptr)
			{
				int orientacio = -1;
				for (int i = 1; i < m_nElements_temp; i++)
				{
					if (afegeix[i - 1].getX() == afegeix[i].getX())orientacio = 1;
					else if (afegeix[i - 1].getY() == afegeix[i].getY())orientacio = 0;
				}

				int x_min = afegeix[0].getX();
				int y_min = afegeix[0].getY();

				for (int i = 0; i < m_nElements_temp; i++)
				{
					if (orientacio == 0)
					{
						if (x_min > afegeix[i].getX())x_min = afegeix[i].getX();
						y_min = afegeix[i].getY();
					}
					else if (orientacio == 1)
					{
						if (y_min > afegeix[i].getY())y_min = afegeix[i].getY();
						x_min = afegeix[i].getX();
					}
				}
				//afegir vaixell
				if (m_nElements_temp > 0 && m_nVaixells < 10)
				{
					m_jugador1.afegeixVaixell(x_min, y_min, orientacio, m_nElements_temp);
					cout << "Vaixell afegit a la posició " << x_min << " , " << y_min << " amb orientacio " << orientacio << " i " << m_nElements_temp << " caselles" << endl;
					m_nVaixells++;
					m_jugador1.setnVaixellsVius(m_nVaixells);
					m_tauler.setVaixells(m_nVaixells);
				}
			}
		}
		//llegir caselles amb do while
		if (afegint && afegeix != nullptr)
		{
			bool repetit = false;
			int i = 0;
			while (i < m_nElements_temp && !repetit)
			{
				if (x == afegeix[i].getX() && y == afegeix[i].getY())
				{
					for (int j = i; j < m_nElements_temp - 1; j++)
					{
						afegeix[j].setX(afegeix[j + 1].getX());
						afegeix[j].setY(afegeix[j + 1].getY());
					}
					afegeix[m_nElements_temp].setX(0);
					afegeix[m_nElements_temp].setY(0);
					m_nElements_temp--;
					repetit = true;
					m_tauler.setTauler(1, x, y, 0);
				}
				i++;
			}
			if (!repetit)
			{
				afegeix[m_nElements_temp].setX(x);
				afegeix[m_nElements_temp].setY(y);
				m_nElements_temp++;
				m_tauler.setTauler(1, x, y, 1);
			}
		}
		else if (!afegint || afegeix == nullptr)
		{
			if (afegeix != nullptr)
			{
				delete[] afegeix;
				afegeix = nullptr;
			}
			afegeix = new Llista[TAMANY_MINIM];
			m_nElements_temp = 0;
		}
	}
	else cout << "maxim de vaixells assolit" << endl;
		

}

void Partida::permetComencar(bool permis)
{
	if (m_nVaixells >= 9)setPreparacio(!permis);
	cout << "Llista vaixells:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<m_jugador1.getVaixell(i).getFila();
		cout<<", "<< m_jugador1.getVaixell(i).getColumna();
		cout << ", " << m_jugador1.getVaixell(i).getDireccio();
		cout << ", " << m_jugador1.getVaixell(i).getNcaselles() << endl;
	}
}

void Partida::guarda()
{
	ofstream fitxer;
	fitxer.open("data/PartidaGuardada.txt");
	//fitxer << "MatriuJugador: " << endl;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			fitxer << m_tauler.getPosicioPropi(i, j)<<" ";
		}
		fitxer << endl;
	}
	//fitxer << "MatriuEnemic: " << endl;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			fitxer << m_tauler.getPosicioContrari(i, j)<<" ";
		}
		fitxer << endl;
	}
	//fitxer << "Vaixells jugador: " << endl;
	Vaixell aux;
	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			aux = m_jugador1.getVaixell(i);
			fitxer << aux.getFila()<< " ";
			fitxer << aux.getColumna()<< " ";
			fitxer << aux.getDireccio() << " ";
			fitxer << aux.getNcaselles() << " ";
			fitxer << aux.getNCasellesVives() << " ";
			fitxer << endl;
		}
		if (i >= 10)
		{
			aux = m_enemic.getVaixell(i-10);
			fitxer << aux.getFila() << " ";
			fitxer << aux.getColumna() << " ";
			fitxer << aux.getDireccio() << " ";
			fitxer << aux.getNcaselles() << " ";
			fitxer << aux.getNCasellesVives() << " ";
			fitxer << endl;
		}
		
	}
	fitxer.close();
}

void Partida::carrega()
{
	preparacio = false;
	m_enemic.setnVaixellsVius(0);
	m_tauler.setAux(true);
	ifstream fitxer;
	fitxer.open("data/PartidaGuardada.txt");
	//fitxer << "MatriuJugador: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int aux;
			fitxer >> aux;
			m_tauler.setTauler(1, i, j, aux);
		}
	}
	//fitxer << endl;
	//fitxer << "MatriuEnemic: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int aux;
			fitxer >> aux;
			m_tauler.setTauler(0, i, j, aux);
		}
	}
	//	fitxer << endl;
		//fitxer << "Vaixells jugador: " << endl;
	//m_jugador1.actualitza();
	//fitxer << "Vaixells enemic: " << endl;
	int fila, columna, direccio, ncaselles, ncasellesvives;
	Vaixell aux;
	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			fitxer >> fila;
			aux.setFila(fila);
			fitxer >> columna;
			aux.setColumna(columna);
			fitxer >> direccio;
			aux.setDireccio(direccio);
			fitxer >> ncaselles;
			aux.setNCaselles(ncaselles);
			fitxer >> ncasellesvives;
			for (int j = ncaselles; j > ncasellesvives; j--)
				aux.tocat();

			m_jugador1.copiaVaixell(aux);
		}
		//m_jugador1.actualitza();
		if (i >= 10)
		{
			fitxer >> fila;
			aux.setFila(fila);
			fitxer >> columna;
			aux.setColumna(columna);
			fitxer >> direccio;
			aux.setDireccio(direccio);
			fitxer >> ncaselles;
			aux.setNCaselles(ncaselles);
			fitxer >> ncasellesvives;
			for (int j = ncaselles; j > ncasellesvives;j--)
				aux.tocat();
			
			m_enemic.copiaVaixell(aux);
		}
	}
	//m_enemic.actualitza();
	//m_jugador1.actualitza();
	fitxer.close();
}