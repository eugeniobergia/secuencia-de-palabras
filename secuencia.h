#ifndef __SECUENCIA_H__
#define __SECUENCIA_H__

#include <stddef.h>
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
*/

#define forr(i,a,n) for(int i = a;i < n;++i)

#ifdef _WIN32
  #define clear "cls"
#else
#ifdef _WIN64
  #define clear "cls"
#else
  #define clear "clear"
#endif
#endif

typedef struct{
	char nombre[30];
	bool vivo;
}jugador;

void reglas();

void datosJugadores(jugador jug[],int cantJugadores);

char letraAleatoria();

char* ingresar();

bool verificar(char palabra[],char *lista[],char letra,int numPalabra,int cantPalabras);

void pausa();

int jugar(jugador jug[],int cantJugadores,int cantJugadoresVivos);

#endif
