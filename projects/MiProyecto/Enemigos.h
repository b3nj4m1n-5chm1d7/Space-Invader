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
	
	//Movimiento enemigo
	void mover();
	void dibujar();
	
	//Colision con bala del jugador
	void detectarColision();
	
	//Deteccion de columnas restantes
	void buscarVida(int& minCol, int& maxCol);
	
	//Puntos que se otorgan
	void mostrarPuntos();
	
	//Etapas para victoria
	bool TodosMuertos();
	void Victoria();
	
	//Caracteristicas de la bala enemiga
	void DisparoAleatorio();
	void BalaActiva();
	
private:
	
	Jugador* jugador;
	
	BaseEnemigo* matriz[FILAS][COLUMNAS];
	
	//Estadisticas para el enemigo
	int offsetX;
	int offsetY;
	int dir;
	int velocidad;
	
	int valor;
	
	//Tiempo para moverse
	clock_t tempoEnem;
	clock_t pasoEnem;
	
	//Si posicion enemigo fuera igual que posicion jugador en el eje "Y"
	bool derrota;
	
	//Coordenadas de la bala
	struct BalaEnemigo{
		int x;
		int y;
		
		bool activa;
	};
	
	BalaEnemigo bala;
	
	clock_t tempoBala;
	clock_t pasoBala;
	
};

#endif

