#include "Jugador.h"

//Establece una nueva instancia de dibujo
void draw(int x, int y){
	putchxy(x,y,'A');
}

//Establece una fase de borrado
void erase(int x, int y){
	putchxy(x,y,' ');
}

//Se establecen las caracteristicas de la "nave" principal
Jugador::Personaje(){
	
	//Coordenadas "base"
	x=60;
	y=30;
	
	//Se dibuja la nave dentro de las coordenadas establecidas
	putchxy(x,y,'A'); 
	
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
			}
			
			//Se redibuja la "nave" utilizando las nuevas coordenadas
			putchxy(x,y,'A');
		}
	}
}
