#include "Jugador.h"

//Establece una nueva instancia de dibujo
void draw(int x, int y){
	putchxy(x,y,'A');
}

//Establece una fase de borrado
void erase(int x, int y){
	putchxy(x,y,' ');
}
	
//Etapa de dibujo y de borrado para la bala
void dibujo(int f,int g){
	putchxy(f,g,'|');
}
	
void borrar(int f, int g){
	putchxy(f,g,' ');
}

//Se establecen las caracteristicas de la "nave" principal
Jugador::Jugador(){
	
	//Coordenadas "base"
	x=60;
	y=30;
	
	f = x;
	g = 30;
	
	vidas = 3;
	
	invencible = false;
	duracionInv = CLOCKS_PER_SEC;
	
	parpadeo = true;
	
	//Se dibuja la nave dentro de las coordenadas establecidas
	putchxy(x,y,'A'); 
	
	shoot = false;
	
	//Control de la velocidad de la bala
	int velocidad = 18;
	pasoBala = CLOCKS_PER_SEC/velocidad;
	tempoBala = clock();
}

void Jugador::actualizar(){
	
	if (invencible){
		
		if (clock()- tempodano > duracionInv){
			invencible = false;
			parpadeo = true;
			putchxy(x,y,'A');
		}
		else{
			if (parpadeo){
				putchxy(x,y,' ');
				parpadeo = false;
			}
			else {
				putchxy(x,y,'A');
				parpadeo = true;
			}
		}
	}
	
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

//Se establece una deteccion de la bala
bool Jugador::DisparoActivo(){
	return shoot;
}

//Se detectan las coordenadas de la bala
int Jugador::balaX(){
	return f;
}

int Jugador::balaY(){
	return g;
}

//Establece una "dasaparición" para la bala
bool Jugador::destruirBala(){
	if (shoot){
		putchxy(f,g,' ');
		shoot = false;
	}
}

int Jugador::posX(){
	return x;
}

int Jugador::posY(){
	return y;
}

void Jugador::recibirDano(){
	
	if (invencible) return;
	
	vidas--;
	invencible = true;
	tempodano = clock();
	
	if (vidas <= 0){
		system("cls");
		textcolor(RED);
		cout<<endl<<endl<<endl<<endl<<endl<<"                                  Perdiste";
	}
}
