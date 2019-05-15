#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "secuencia.h"

void reglas(){
  system(clear);
  printf("Bienvenidos a SECUENCIA DE PALABRAS!!\n\n"
  			 "REGLAS:\n"
         "* Debe haber entre 2 y 5 jugadores\n"
         "* Las palabras no se deben repetir\n"
         "* Las palabras deben comenzar con la letra mostrada,\n"
         "  a excepcion de las letras K, V, X, Y y Z, que pueden estar contenidas\n"
         "* El juego no hace diferencia entre mayus. y minus.\n"
         "* La ronda finaliza cuando un jugador queda eliminado o se llega a 15\n"
         "  palabras correctas\n"
         "* El juego finaliza cuando queda un solo jugador\n"
         "\nPresione ENTER para continuar...\n");
  getchar();
  system(clear);
}

void datosJugadores(jugador jug[],int cantJugadores){
	forr(i,0,cantJugadores){
		printf("Ingrese el nombre del jugador nro. %d: ", i + 1);
		scanf(" %s", jug[i].nombre);
		jug[i].vivo = true;
	}
}

char letraAleatoria(){
	char letra;
	do{
    letra = (rand() % 26) + 65;
  }while(letra == 'W');
  return letra;
}

char* ingresar(){
  char temp[256];
  char *palabra;
  scanf(" %s", temp);
  forr(i,0,strlen(temp))
  	temp[i] = toupper(temp[i]);
  palabra = malloc(sizeof(char) * strlen(temp) + 1);
  strcpy(palabra,temp);
  return palabra;
}

bool verificar(char palabra[],char *lista[],char letra,int numPalabra,int cantPalabras){
  bool correcto = false;

  if(numPalabra == cantPalabras){
    if(letra == 'K' || letra == 'V' || letra == 'X' || letra == 'Y' || letra == 'Z'){
      forr(i,0,strlen(palabra))
        if(palabra[i] == letra) correcto = true;
    }else if(palabra[0] == letra) correcto = true;

    forr(i,0,cantPalabras){
      if(!strcmp(lista[i],palabra)) correcto = false;
    }

    if(correcto){
      lista[cantPalabras] = malloc(sizeof(char) * strlen(palabra) + 1);
      strcpy(lista[cantPalabras],palabra);
    }
  }

  if(numPalabra < cantPalabras)
    if(!strcmp(lista[numPalabra],palabra)) correcto = true;

  return correcto;
}

void pausa(){
	printf("Presione ENTER para continuar...\n");
	getchar();
	getchar();
	system(clear);
}

int jugar(jugador jug[],int cantJugadores,int cantJugadoresVivos){
	char letra = letraAleatoria(); //LA LETRA ALEATORIA
	bool correcto = true; //INDICA SI LA PALABRA INGRESADA ES CORRECTA
	int cantPalabras = 0; //INDICA LA CANTIDAD DE PALABRAS QUE HAY EN TOTAL
	char *lista[15]; //UNA LISTA CON TODAS LAS PALABRAS INGRESADAS
	int numJugador = 0;

	while(correcto && cantPalabras < 15){
		int numPalabra; //INDICA EL NUMERO DE PALABRA EN EL QUE ESTOY

		if(jug[numJugador].vivo){
			printf("La letra es %c\n", letra);
		  printf("Ingrese las palabas de %s:\n", jug[numJugador].nombre);
		  for(numPalabra = 0;numPalabra < cantPalabras + 1 && correcto;numPalabra++){
		    char *palabra = ingresar(); //LA PALABRA QUE INGRESO

		    correcto = verificar(palabra,lista,letra,numPalabra,cantPalabras);
		  }
		  if(correcto) printf("Correcto!!!\n");
		  else{
		    printf("Incorrecto!!! %s queda eliminado!\n", jug[numJugador].nombre);
		    jug[numJugador].vivo = false;
		    cantJugadoresVivos--;
		  }

		  cantPalabras++;
		  pausa();
		}

		if(numJugador == cantJugadores - 1)
			numJugador = 0;
		else numJugador++;
	}

	if(cantPalabras == 15 && correcto)
		printf("Llegaron a las 15 correctas!! ");
	if(cantJugadoresVivos > 1)
		printf("Cambiamos de letra...\n");

	return cantJugadoresVivos;
}
