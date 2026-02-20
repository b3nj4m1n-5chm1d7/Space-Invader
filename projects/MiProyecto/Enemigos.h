#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include<iostream>
#include <conio2.h>
#include <ctime>

#include "BaseEnemigo.h"
#include "Jugador.h"

using namespace std;

const int FILAS = 4;
const int COLUMNAS = 10;


class Enemigos {
	
public:
	
	Enemigos(Jugador* j);
	
	void posEnemigos();
	
	void mover();
	void dibujar();
	
	void detectarColision();
	
	void buscarVida(int& minCol, int& maxCol);
	
	void mostrarPuntos();
	
private:
	
	Jugador* jugador;
	
	BaseEnemigo* matriz[FILAS][COLUMNAS];
	
	int offsetX;
	int offsetY;
	int dir;
	int velocidad;
	
	int valor;
	
	clock_t tempoEnem;
	clock_t pasoEnem;
	
	bool derrota;
	
};

#endif

