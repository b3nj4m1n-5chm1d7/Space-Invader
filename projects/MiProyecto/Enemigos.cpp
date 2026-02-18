#include "Enemigos.h"

#include "TankEnemy.h"
#include "BasicEnemy.h"
#include "MedEnem.h"

void Enemigos::dibujar(){
	
	for (int f = 0; f<FILAS; f ++){
		for (int c = 0; c<COLUMNAS; c++){
			
			if (matriz[f][c]->viviendo()){
				int x = offsetX + c*4;
				int y = offsetY + f*2;
				
				putchxy(x, y, matriz[f][c]->sprite());
			}
		}
	}
}

void Borrar(int offsetX, int offsetY, BaseEnemigo* matriz[FILAS][COLUMNAS]){
	
	for (int f = 0; f <FILAS; f++){
		for (int c = 0; c < COLUMNAS; c++){
			
			if (matriz[f][c]->viviendo()){
				
				int x = offsetX +c*4;
				int y = offsetY + f*2;
				
				putchxy(x, y, ' ');
			}
		}
	}
}

Enemigos::Enemigos(){
	
	offsetX = 20;
	offsetY = 3;
	dir = 2;
	
	derrota = false;
	
	velocidad = 5;
	
	pasoEnem = CLOCKS_PER_SEC/velocidad;
	tempoEnem = clock();
	
	for (int f = 0; f <FILAS; f ++){
		for (int c = 0; c <COLUMNAS; c++){
			
			if (f == 0){
				matriz[f][c] = new TankEnemy();
			}
			else if (f==1 ||f==2){
				matriz[f][c] = new MedEnem();
			}
			else{
				matriz[f][c] = new BasicEnemy();
			}
		}
	}
}

void Enemigos::mover() {
	
	if(clock() - tempoEnem > pasoEnem){
	
		Borrar(offsetX, offsetY, matriz);
		offsetX += dir;
		
		if (offsetX + COLUMNAS*4 >= 100){
			offsetX = 100 - COLUMNAS*4;
			dir = -dir;
			offsetY++;
		}
		if (offsetX<= 20){
			offsetX = 20;
			dir = -dir;
			offsetY++;
		}
		dibujar();
	
		tempoEnem = clock();
	}
	
	if (offsetY >= 28){
		derrota = true;
	}
	if (derrota){
		offsetX = 50;
		dir = 0;
		velocidad = 0;
		system("cls");
		for (int i = 0; i < 10; i++){
			cout<<endl;
		}
		cout<<"                                             Perdiste"<<endl<<"                                         Intentalo otra vez";
	}
}
