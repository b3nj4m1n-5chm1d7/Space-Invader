#ifndef TANKENEMY_H
#define TANKENEMY_H
#include "BaseEnemigo.h"

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class TankEnemy : public BaseEnemigo {
	
public:
	
	TankEnemy();
	
	//Apariencia
	char sprite() override {return 'M';}
	//Puntos que otorga
	char puntos() override {return 30;}
	
private:
	
};

#endif

