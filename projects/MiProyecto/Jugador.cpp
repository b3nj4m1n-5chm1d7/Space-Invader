#include "Jugador.h"
#include <ctime>

//Establece una nueva instancia de dibujo
void draw(int x, int y){
	putchxy(x,y,'A');
}

//Establece una fase de borrado
void erase(int x, int y){
	putchxy(x,y,' ');
}
	
void dibujo(int f,int g){
	putchxy(f,g,'|');
}
	
void borrar(int f, int g){
	putchxy(f,g,' ');
}

//Se establecen las caracteristicas de la "nave" principal
Jugador::Personaje(){
	
	//Coordenadas "base"
	x=60;
	y=30;
	
	f = x;
	g = 30;
	
	bool shoot = false;
	
	//Se dibuja la nave dentro de las coordenadas establecidas
	putchxy(x,y,'A'); 
	
	//Control de la velocidad de la bala
	clock_t tempoBala;
	clock_t pasoBala;
	int velocidad = 18;
	
	pasoBala = CLOCKS_PER_SEC/velocidad;
	tempoBala = clock();
	
	while(true){
		
		if(kbhit()) {
			
			int tecla=getch();
			
			//Se establece movimiento al presionar una tecla determinada
			switch(tecla){
			
			//Movimiento hacia la izquierda
			case 'a':
				
				erase(x,y); 
				x--;
				draw(x,y);
				
				break;
			
			//Movimiento hacia la derecha
			case 'd':
				
				erase(x,y); 
				x++;
				draw(x,y);
				
				break;
			
			//Disparo
			case 32:
				
				//Detecta si no hay disparo previo
				if (!shoot){
					shoot = true;
					f = x;
					g = y - 1;
					dibujo(f,g);
					tempoBala = clock();
				}
				
				break;
			}
			
			//Se redibuja la "nave" utilizando las nuevas coordenadas
			putchxy(x,y,'A');
			
			//Se limita el movimiento del eje X, para no superar el límite del juego
			if (x >= 100){
				erase(x,y);
				x = 100;
				draw(x,y);
			}
			if (x <= 20){
				erase(x,y);
				x = 20;
				draw(x,y);
			}
		}
		
		//Establece las caracteristicas que posee el disparo
		if (shoot){
			
			if (tempoBala + pasoBala <clock()){
				borrar(f,g);
				g--;
				
				if (g <= 0){
					shoot = false;
				} else {
					dibujo(f,g);	
				}
				
				tempoBala = clock();
			}
		}
	}
}
