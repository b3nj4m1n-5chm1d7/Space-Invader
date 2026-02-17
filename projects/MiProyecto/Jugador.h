#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class Jugador {
	
public:
	
	Jugador();
	void actualizar();
	
private:
	
	int x;
	int y;
	
	int f;
	int g;
	
	clock_t tempoBala;
	clock_t pasoBala;
	
	bool shoot;
	
};

#endif

