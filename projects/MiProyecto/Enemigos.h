#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class Enemigos {
	
public:
	
	Enemigos();
	
	void mover();
	
	
private:
	
	int pos;
	int alt;
	int dir;
	int contador;
	int velocidad;
	
	clock_t tempoEnem;
	clock_t pasoEnem;
	
};

#endif

