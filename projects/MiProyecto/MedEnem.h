#ifndef MEDENEM_H
#define MEDENEM_H
#include "BaseEnemigo.h"

#include<iostream>
#include <conio2.h>
#include <ctime>

using namespace std;



class MedEnem : public BaseEnemigo {

public:
	
	MedEnem();
	
	char sprite() override {return 'H';}
	char puntos() override {return 15;}
	
private:

};

#endif

