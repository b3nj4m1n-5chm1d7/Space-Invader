#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "BaseEnemigo.h"

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class BasicEnemy : public BaseEnemigo {
	
public:
	
	BasicEnemy();
	
	char sprite() override {return 'W';}
	char puntos() override {return 10;}
	
private:
	
};

#endif

