#include "Enemigos.h"

void drawEnm( int pos, int alt){
	putchxy(pos,alt,'W');
}

void borrarEnm(int pos,int alt){
	putchxy(pos,alt,' ');
}

Enemigos::Enemigos(){
	
	pos = 60;
	alt = 3;
	dir = 2;
	
	velocidad = 8;
	
	putchxy(pos,alt,'W');
	
	pasoEnem = CLOCKS_PER_SEC/velocidad;
	tempoEnem = clock();
}

void Enemigos::mover() {
	
	if(clock() - tempoEnem > pasoEnem){
	
		borrarEnm(pos,alt);
		pos+= dir;
		drawEnm(pos,alt);
	
		tempoEnem = clock();
	}
}
