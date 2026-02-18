#ifndef BASEENEMIGO_H
#define BASEENEMIGO_H

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class BaseEnemigo{
	
protected:
	
	bool vivo;
	
public:
	
	BaseEnemigo();
	
	virtual ~BaseEnemigo() {}
	
	virtual char sprite() = 0;
	virtual char puntos() = 0;
	
	bool viviendo() {return vivo;}
	bool muerto() {vivo = false;}
	
	
private:
	
};

#endif

