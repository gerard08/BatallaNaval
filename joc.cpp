#include "joc.h"
#include "Partida.h"
#include <time.h>

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc(bool mode)
{
	int x, y;

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(MIDA_X, MIDA_Y);
	
	//Mostrem la finestra grafica
	pantalla.show();
	bool animat = false;
	Partida nova;
	nova.setTf(false);
	bool passat = false;
	nova.IniciaEnemic();
	nova.setPreparacio(true);
	nova.setAcabat(false);
	Sprite victoria;
	Sprite derrota;
	victoria.create("data/perdut.png");
	derrota.create("data/guanyat.png");
	//bool fi;
	bool guanyador;
	do
	{
		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();
		nova.visualitza(passat);
		if (mode)nova.setTf(false);
		if (animat)
		{
			if (guanyador)
			{
				victoria.draw(0, 0);
			}
			else
			{
				derrota.draw(0, 0);
			}
		}
		if (passat)
		{
			if (nova.getCarrego())
			{
				
				nova.carrega();
				nova.setCarrego(false);
				nova.setAfegint(false);
				nova.setPreparacio(false);
				victoria.create("data/perdut.png");
				derrota.create("data/guanyat.png");
			}
			if (Mouse_getButLeft())
			{
				x = Mouse_getX();
				y = Mouse_getY();
				if (!nova.getPreparacio() && x < 520 - 52)
				{
					if (nova.getnVaixells() == 10)
						x = 600;
				}
				x /= 52;
				y /= 52;
				if (!nova.getPreparacio())nova.atac(x - 11, y);
				else if (nova.getPreparacio())
				{
					if (x == 10 && y == 0)nova.setAfegint(false);
					else
					{
						nova.setAfegint(true);
					}
					nova.afegeixVaixell(x, y);
				}
				if (x == 10 && y == 9)nova.permetComencar(true);
				if (x == 10 && y == 1)nova.guarda();
			}
		}
		if (!nova.getPreparacio())
		{
			if (nova.getAcabat(guanyador))
			{	
				if (guanyador)
				{
					int i = 0;
					if (!animat)
					{
						//animació has perdut
						while (i < 1200)
						{
							victoria.draw(-1200 + i, 0);
							pantalla.update();
							SDL_Delay(0.5);
							i++;
						}
						animat = true;
					}
				}
				if (!guanyador)
				{
					int i = 0;
					if (!animat)
					{
						//animació has perdut
						while (i < 1200)
						{
							derrota.draw(1200 - i, 0);
							pantalla.update();
							SDL_Delay(0.5);
							i++;
						}
						animat = true;
					}
				}
			}
		}
		//nova.getAcabat(guanyador);
		pantalla.update();

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && nova.getTf()==false);
	// Sortim del bucle si pressionem ESC

}