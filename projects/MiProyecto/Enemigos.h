#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include<iostream>
#include <conio2.h>
#include <ctime>

#include "BaseEnemigo.h"

using namespace std;

const int FILAS = 4;
const int COLUMNAS = 10;


class Enemigos {
	
public:
	
	Enemigos();
	
	void mover();
	void dibujar();
	
	
private:
	
	BaseEnemigo* matriz[FILAS][COLUMNAS];
	
	int offsetX;
	int offsetY;
	int dir;
	int velocidad;
	
	clock_t tempoEnem;
	clock_t pasoEnem;
	
	bool derrota;
	
};

#endif

