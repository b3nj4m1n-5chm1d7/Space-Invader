#include "Enemigos.h"
#include <windows.h>

//Se llama a cada tipo de enemigo
#include "TankEnemy.h"
#include "BasicEnemy.h"
#include "MedEnem.h"

//Se establece una etapa de dibujo
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

//Se establece una fase de borrado
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

//Se establecen las caracteristicas generales de los enemigos
Enemigos::Enemigos(Jugador* j){
	
	jugador = j;
	
	//Posicion de los enemigos al empezar
	offsetX = 20;
	offsetY = 3;
	//Distancia que recorren los enemigoas
	dir = 1;
	
	valor = 0;
	
	derrota = false;
	
	//Velocidad del enemigo
	velocidad = 5;
	
	pasoEnem = CLOCKS_PER_SEC/velocidad;
	tempoEnem = clock();
	
	bala.activa = false;
	
	pasoBala = CLOCKS_PER_SEC *2;
	tempoBala = clock();
	
	//Se dibuja cada tipo de enemigo en una fila determinada
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

//Establece las caracteristicas del movimiento enemigo
void Enemigos::mover() {

	//Se evitan "parpadeos" en caso de finalizar la partida
	if (dir == 0) return;
	
	//Se mueve automaticamenet ded izquierda a derecha, bajando una vez en cada ocasión
	if(clock() - tempoEnem > pasoEnem){
		
		Borrar(offsetX, offsetY, matriz);
		offsetX += dir;
		
		int minCol;
		int maxCol;
		buscarVida(minCol,maxCol);
		
		//Se detiene en caso de no haber más enemigos
		if (minCol == -1) return;
		
		//Se establecen bordes que se actualizan
		int bordeIzq = offsetX + minCol*4;
		int bordeDer = offsetX + maxCol*4;
		
		if (bordeDer >= 100){
			dir = -dir;
			offsetY++;
		}
		if (bordeIzq <= 20){
			dir = -dir;
			offsetY++;
		}
		dibujar();
		
		tempoEnem = clock();
	}
	
	//Se crea una fase de derrota si los enemigos llegan muy abajo
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
	
	//Se llaman a las caracteristicas de los enemigos al ser impactados por las nalas del jugador
	detectarColision();
	if (!TodosMuertos()){
		Victoria();
		return;
	}
	mostrarPuntos();
	DisparoAleatorio();
	BalaActiva();
}

//Detecta la colision de la bala con el enemigo que corresponda
void Enemigos::detectarColision(){
	
	if(!jugador->DisparoActivo()) return;
	
	int bx = jugador->balaX();
	int by = jugador->balaY();
	
	for (int f = 0; f<FILAS; f++){
		for(int c = 0; c<COLUMNAS; c++){
			
			if (matriz[f][c]->viviendo()){
				
				int ex = offsetX + c*4;
				int ey = offsetY + f*2;
				
				//Busca si la posicion de la bala es la misma que la de algun enemigo
				if (bx == ex && by == ey){
					valor += matriz[f][c]->puntos();
					matriz[f][c]->muerto();
					
					putchxy(ex,ey,'*');
					Sleep(30);
					putchxy(ex,ey,' ');
					
					jugador->destruirBala();
					return;
				}
			}
		}
	}
}

//Detecta si todavía hay algun enemigo sobreviviente en cualquiera de las columnas, y las actualiza en caso de no haber ninguno
void Enemigos::buscarVida(int& minCol, int& maxCol){
	
	minCol = COLUMNAS;
	maxCol = -1;
	
	for (int f = 0; f < FILAS; f++){
		for (int c = 0; c < COLUMNAS; c ++){
			
			if (matriz[f][c]->viviendo()){
				
				if ( c < minCol) minCol = c;
				
				if ( c > maxCol) maxCol = c;
			}
		}
	}
}

//Indica los puntos que posee el jugador
void Enemigos::mostrarPuntos(){
	
	gotoxy(5,1);
	cout<<"Puntos: "<<valor;
	
}

//Detecta si todavía queda vivo cualquier enemigo en pantalla
bool Enemigos::TodosMuertos(){
	
	for (int f = 0; f < FILAS; f++){
		for (int c = 0; c < COLUMNAS; c++){
			
			if (matriz[f][c]->viviendo()){
				return true;
			}
		}
	}
	return false;
}

//Mensaje de Victoria en caso de matar a todos los enemigos, indicando los puntos acumulados
void Enemigos::Victoria(){
	system("cls");
	
	for (int i = 0; i < 10; i++){
		cout<<endl;
	}
	
	cout<<"                                  GANASTE!"<<endl;
	cout<<"                            Mataste a todos los enemigos"<<endl;
	cout<<"                                Puntos: "<<valor;
	
	dir = 0;
	velocidad = 0;
}

//Selecciona una Columna aleatoria para disparar, y dispara siempre desde la fila más cercana al jugador
void Enemigos::DisparoAleatorio(){
	
	if (bala.activa) return;
	
	if (clock() - tempoBala < pasoBala) return;
	
	int col = rand() % COLUMNAS;
	
	for (int f = FILAS - 1; f >= 0; f--){
		
		if (matriz[f][col]->viviendo()){
			bala.x = offsetX + col*4;
			bala.y = offsetY + f*2 + 1;
			bala.activa = true;
			
			break;
		}
	}
	tempoBala = clock();
}

//Detecta si alguna bala se encuentra activa en pantalla, en caso de ser negativo, genera un nuevo disparo
void Enemigos::BalaActiva(){
	
	if (!bala.activa) return;
	
	putchxy (bala.x,bala.y,' ');
	
	bala.y++;
	
	if (bala.y >30){
		bala.activa = false;
		return;
	}
	
	putchxy(bala.x,bala.y,'.');
}
