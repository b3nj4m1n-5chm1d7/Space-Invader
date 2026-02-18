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
	
	char sprite() override {return 'M';}
	char puntos() override {return 30;}
	
private:
	
};

#endif

