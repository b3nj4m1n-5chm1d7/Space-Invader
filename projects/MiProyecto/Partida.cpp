#include "Partida.h"
#include "Jugador.h"
#include "Pantalla.h"
#include "Enemigos.h"

Pantalla p;

//Se establece una etapa de inicio (pantalla de inicio)
void comienzo(){
	
	//Se establece una distancia del lado superior hasta el texto
	for (int i = 0;  i < 6; i ++){
		cout <<endl;
	}
	
	textcolor(BLUE);
	//Se presenta el titulo e instruciones del juego
	cout << "                                                ============================="<<endl;
	cout << "                                                       Space Invaders        "<<endl<<endl;
	cout << "                                                     Intro Programacion        "<<endl;
	cout << "                                                      Benjamin Schmidt        "<<endl;
	cout << "                                                ============================="<<endl<<endl;
	textcolor(LIGHTGREEN);
	cout << "                                                       Instrucciones:        "<<endl;
	cout << "                            Movimiento: presione la tecla A para mover la nave hacia la izquierda,        "<<endl;
	cout << "                                        presione la tecla D para mover hacia la derecha        "<<endl;
	cout << "                                   Disparo: presione la tecla ESPACIO para accionar el disparo        "<<endl<<endl;
	textcolor(DARKGRAY);
	cout << "                                        Gana si todas las naves enemigas son destruidas        "<<endl;
	textcolor(RED);
	cout << "                                  Pierde si queda sin vidas al alcanzarlo cualquier disparo enemigo,        "<<endl;
	cout << "                                         o si los enemigos alcanzan la misma linea que el jugados        "<<endl<<endl<<endl;
	textcolor(WHITE);
	cout << "                                           Presiona cualquier tecla para comenzar..."<<endl;
	
	//Se espera a que el jugador presione alguna tecla
	getch();
	//Se limpia la pantalla
	system("cls");
}

//Se establece una etapa donde se cargan los contenidos del juego
void andar(){
	
	p.Interfaz();
	
	Jugador player;
	Enemigos enemigos(&player);
	
	while(true){
	enemigos.mover();
	player.actualizar();
	
	Sleep(30);
	}
}
	
Partida::inicio() {
	
	comienzo();
	andar();
}

