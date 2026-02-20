#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class Enemigos;

class Jugador {
	
public:
	
	Jugador();
	void actualizar();
	
	bool DisparoActivo();
	int balaX();
	int balaY();
	
	bool destruirBala();
	
private:
	
	int x;
	int y;
	
	int f;
	int g;
	
	int puntos;
	
	clock_t tempoBala;
	clock_t pasoBala;
	
	bool shoot;
	
};

#endif

