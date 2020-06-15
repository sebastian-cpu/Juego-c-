#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;


// variables globales 

int cuerpo[200][2];
char tecla;
int tamanio = 18;
int x = 10, y =12, n=1;
int dir = 3;
int xc = 30, yc = 15;
int puntos= 0;
char file[] = " puntajes.txt";
int velocidad = 80, h = 1;



#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

void gotoxy(int x, int y);
void pintar();
void guardar_posicion();
void dibujar_serpiente();
void borrar_cuerpo();
void teclear();
void comida();
void score();
bool perdiste();
void puntajes_jugadores();
void ver_jugadores();
void cambiar_velocidad();

int main(int argc, char** argv) {
	
	system("color 72");
 	pintar();
 	
 	gotoxy(xc,yc);
 	cout<<char(36);
 	
 	
 	while(tecla != ESC && !perdiste()) {
 	borrar_cuerpo();	
	guardar_posicion();
	dibujar_serpiente();
	teclear();
	teclear();
	comida();
	score();
	void puntajes_jugadore();
	
	if(dir == 1){
		y--;
	}
	if(dir == 2){
		y++;
	}
	if(dir == 3){
		x++;
	}
	if(dir == 4){
		x--;
	}
	Sleep(velocidad);
}
	gotoxy(40,1);
	cout<<" Has perdido, vuelve a intentarlo";
	system("pause");
	system("cls");
	puntajes_jugadores();
	system("cls");
	ver_jugadores();
	
	system("pause>null");//pausar el sistema con cualquier tecla continua
	return 0;
}
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}
void pintar(){
	//lineas horizontales
	for(int i = 2;i< 78;i++){
		gotoxy(i,3);
		cout<<char(205);
		gotoxy(i,23);
		cout<<char(205);
		
	}
	//lineas verticales
		for(int i = 4;i< 23;i++){
		gotoxy(2,i);
		cout<<char(186);
		gotoxy(77,i);
		cout<<char(186);
		
	}
	//esquineros
	
	gotoxy(2,3);
	cout<<char(201);
	gotoxy(2,23);
	cout<<char(200);
	gotoxy(77,3);
	cout<<char(187);
	gotoxy(77,23);
	cout<<char(188);	

}
void guardar_posicion() {
	cuerpo[n][0] = x;
	cuerpo[n][1] = y;
	n++;
	
	if(n == tamanio){
		n = 1;
	}
}
void dibujar_serpiente(){
	for(int i = 1; i < tamanio;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]);
		cout<<"*";
	}
}
void borrar_cuerpo(){
	gotoxy(cuerpo[n][0], cuerpo[n][1]);
	cout<<" ";
}

void teclear(){
	if(kbhit()){// si un dio una tecla entre en la condicion
		tecla = getch();
		switch(tecla){
			case ARRIBA:
				if(dir !=2){
					dir =1;
				}
				break;
			case ABAJO:
				if(dir != 1){
					dir = 2;
				}
				break;
			case DERECHA:
				if(dir != 4){
					dir = 3;
				}
				break;
			case IZQUIERDA:
				if(dir != 3){
					dir = 4;
				}
				break;
		}
	}
}
void comida(){
	if(xc == x && yc == y){
		//generar coodenadas aleatorias para la comida 
		xc = (rand()%73)+3;
		yc = (rand()%19)+3;
		//aumentar tamaño de serpiente 
		tamanio = tamanio +1;
		puntos = puntos + 10;
		//pintar en pantalla la comida
		gotoxy(xc,yc);
		cout<<char(36);
		cambiar_velocidad();
	}
}
void score(){
	gotoxy(3,1);
	cout<<"Puntaje: "<<puntos;
	
}
bool perdiste(){
	if(y == 3 || y == 23 || x == 77|| x == 2){
		return true;
	}
	for(int j = tamanio -1; j>0;j--){//detecta si la cabeza de la serpiente se choca con el cuerpo
		if(cuerpo[j][0] == x && cuerpo[j][1] == y){
			return true;
		}
	}
	return false;
}
void puntajes_jugadores(){
	char nombre[30];
	ofstream archivo;
	
	archivo.open(file, ios::app);//abrir archivo en modo añadir 
	
	if(archivo.fail()){
		cout<<"Hubo un error"<<endl;
		exit(1);
	}
	
	fflush(stdin);//liberar memoria 
	cout<<" ingresar nombre: ";
	gets(nombre);
	
	archivo<<" Nombre: "<<nombre<<" - Puntajes: "<<puntos;
	
	archivo.close();
}
void ver_jugadores(){
	ifstream archivo; //abrir archivo modo lectura
	string texto;
	
	archivo.open(file, ios::in);
	
	if(archivo.fail()){
		cout<<" Hubo un error";
		exit(1);
	}
	cout<<" HISTORIAL DE JUGADORES"<<endl<<endl;
	
	while(!archivo.eof()){//mientras archivo no haya terminado de recorrer el archivo 
	getline(archivo, texto);
	cout<<texto<<endl;	
}
archivo.close();
}
void cambiar_velocidad(){//camviar velocidad segun condicion
	if(puntos == h*10){
		h++;
		velocidad = velocidad - 10;
	}
}
