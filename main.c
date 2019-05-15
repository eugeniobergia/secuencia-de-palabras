#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "secuencia.h"

//EUGENIO BERGIA y SANTIAGO CÓ

int main(){
	srand(time(NULL));
  reglas();
	int cantJugadores; //LA CANTIDAD DE JUGADORES

	printf("Ingrese la cantidad de jugadores: ");
	do{
		scanf("%d", &cantJugadores);
		if(cantJugadores < 2 || cantJugadores > 5)
			printf("La cantidad de jugadores debe estar en 2 y 5\n");
	}while(cantJugadores < 2 || cantJugadores > 5);

	jugador *jug = malloc(sizeof(jugador)*cantJugadores); //LOS DATOS DE LOS JUGADORES

	system(clear);

	datosJugadores(jug,cantJugadores);

	system(clear);

  int cantJugadoresVivos = cantJugadores; //LA CANTIDAD DE JUGADORES QUE SIGUEN EN JUEGO
  while (cantJugadoresVivos > 1) //CONTINUA HASTA QUE QUEDE UN JUEGADOR
    cantJugadoresVivos = jugar(jug, cantJugadores, cantJugadoresVivos);

  forr(i,0,cantJugadores)
    if(jug[i].vivo) printf("%s gano!!!\n", jug[i].nombre);

	return 0;
}
