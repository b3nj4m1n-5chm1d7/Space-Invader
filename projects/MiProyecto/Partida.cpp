#include "Partida.h"
#include "Jugador.h"
#include "Pantalla.h"

Jugador player;
Pantalla p;

void comienzo(){
	cout<<"hola";
}

void victoria(){
	cout<<"Ganaste";
}
	
Partida::inicio() {
	
	comienzo();
	p.Interfaz();
	player.Personaje();
	victoria();
}

