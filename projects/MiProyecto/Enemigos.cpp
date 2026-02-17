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
	
	velocidad = 5;
	
	putchxy(pos,alt,'W');
	
	pasoEnem = CLOCKS_PER_SEC/velocidad;
	tempoEnem = clock();
}

void Enemigos::mover() {
	
	if(clock() - tempoEnem > pasoEnem){
	
		borrarEnm(pos,alt);
		pos+= dir;
		
		if (pos >= 100){
			pos = 100;
			dir = -2;
			alt++;
		}
		if (pos<= 20){
			pos = 20;
			dir = 2;
			alt++;
		}
		drawEnm(pos,alt);
	
		tempoEnem = clock();
	}
}
