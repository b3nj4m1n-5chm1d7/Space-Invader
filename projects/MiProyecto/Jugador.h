#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class Enemigos;

class Jugador {
	
public:
	
	//Se da valor a las caracteristicas generales del jugador
	Jugador();
	
	//Se llama al movimiento y disparo del jugador
	void actualizar();
	
	//Comparte las distintas caracteristicas del disparo del jugador para otras clases
	bool DisparoActivo();
	int balaX();
	int balaY();
	
	//Comparte la posicion del jugador con otras clases
	int posX();
	int posY();
	
	//"Desaparece" la bala
	bool destruirBala();
	
private:
	
	//Posicion jugador
	int x;
	int y;
	
	//Posicion bala
	int f;
	int g;
	
	//Velocidad de la bala
	clock_t tempoBala;
	clock_t pasoBala;
	
	bool shoot;
	
};

#endif

