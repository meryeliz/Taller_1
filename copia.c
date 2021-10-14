#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



//definicion de estructuras
typedef struct {
    char nom[20];
    char ape[20];
    int edad;    
} equipo;

typedef struct {
    int minP1;
    int minP2;
    int minP3;
    int sumaT;
} tiempo;

/*typedef struct {
	struct equipo jugadores[23];
	struct tiempo minutos[23];
	//char n[20];
	//char a[20];
	//char x[20];
} nombres;
*/

//prototipos de las  funciones
void cargaJugadores(equipo *A);
void cargaTiempos(tiempo *B);
void cantMinutos(equipo *A, tiempo *B);
void totalMin(equipo *I, tiempo *M);
void promedio(tiempo *M );
void partidos(equipo *N, tiempo *T);
void participantesSinJugar(equipo *P, tiempo *T);
//void masMinJugados(equipo *P, tiempo *M, nombres *vecA);
//void ordenamiento(equipo *P, tiempo *M, nombres *vecA);
void listaJugadores(equipo *N, tiempo *T);

int main(int argc, char *argv[]) {
	
	//definicion
	equipo jugadores[23];
	tiempo minutos[23];
//	nombres vector[23];
	
	//variables locales
	int opc, num, sumaTotal;
	char jugadorX;

	
	
	//menu de opciones de 1 a 7
	 do {//el primer do while ingresa al ciclo mostrando las opciones
	 	do {//el segundo do while hace que el usuario no ingrese un numero que no este entre las opciones
	 		//se muestras las opciones a elegir
            printf("MENU DE OPCIONES\n");
        	printf("1- Carga de informacion de los partidos \n");
        	printf("2- Minutos totales de un jugador en los partidos \n");
        	printf("3- Listado minutos totales de los jugadores y calculo de la media \n");
        	printf("4- Listado de totales de minutos por partido \n");
        	printf("5- Listado de jugadores que no participaron de ningun partido \n");
        	printf("6- Listado de jugadores con más minutos en el jueego\n");
        	printf("7- Listado de jugadores por partido\n");
    		printf("Ingrese una opcion:\n");
        	scanf("%d", &opc);
    		fflush(stdin);
		} while (opc < 1 || opc > 7);//ingresa al menu solo si la opcion es entre 1 y 7 
    
		switch(opc) {
			case 1:
				printf("Carga de datos de los jugadores. \n");
				cargaJugadores(jugadores); //convocacion a la funcion
				printf("Carga de minutos jugados en cada partido. \n");
				cargaTiempos(minutos);  //convocacion a la funcion
			    break;	
			case 2:
				printf("Minutos jugados en cada partido de X jugador \n");
				cantMinutos(jugadores, minutos);  //convocacion a la funcion
			    break;
			case 3:
				printf("Se muestra por pantalla las iniciales y minutos jugados en la primera fase. \n");
			    totalMin(jugadores, minutos);  //convocacion a la funcion
			    printf("La media de minutos jugados por todo el plantel es de: \n");
			    promedio(minutos);  //convocacion a la funcion
				break;
			case 4:
				printf("Lista de minutos jugados por partido \n");
				partidos(jugadores, minutos);	//convocacion a la funcion		    
			    break;	
			case 5:
				printf("Listado de los jugadores que no participaron en ningun partido: \n");
			    participantesSinJugar(jugadores, minutos);  //convocacion a la funcion
			    break;
		/*	case 6:
				printf("Los 6 jugadores con mas minutos en la primera fase: \n");
			    masMinJugados(jugadores, minutos, vector);  //convocacion a la funcion
			//    printf("")
			//    ordenamiento(jugadores, minutos, vector);
		*/	    break;
			case 7:
				printf("Nombres de los jugadores que participaron en cada partido: \n");
			    listaJugadores(jugadores, minutos);
			    break;	
		
				
		default:	
			if(opc > 7 ) { //si usa un if para no salir del rango de 1 a 7
				printf("Ingrese otra opcion.\n");
			}

		}
		printf("Ingrese 0 si desea salir.\n");
		scanf("%d", &num);
    	
	} while (num != 0);
	
	system("pause");
	return 0;
}
//ejer 1 terminado
void cargaJugadores(equipo *A) {
    int i;//varible local
    
    //se ingresa los datos de los jugadores en un ciclo
    for(i=0; i < 8; i++) {
        printf ("Ingrese el nombre del jugador %d:\n",i+1);
        fflush(stdin);
        gets((A+i)->nom);
        printf("Ingrese el apellido del jugador %d:\n", i+1);
        fflush(stdin);
        gets((A+i)->ape);
        printf("Ingrese la edad del jugador %d:\n",i+1);
        scanf("%d",&(A+i)->edad);
    }
    printf ("DATOS: \n");
    for(i=0; i < 8; i++) {
        printf(" nombre de jugador %s\n", (A+i)->nom);
        printf(" apellido de jugador %s\n", (A+i)->ape);
        printf(" edad de jugador %d\n", (A+i)->edad);
    }
}


void cargaTiempos (tiempo *B) {
    int i, sumapart;// variables locales
    //se cargan los minutos por jugador en un ciclo
    for(i=0; i < 8; i++) {
    	sumapart = 0;
        printf ("Ingrese los minutos del 1er partido jugador %d \n", i+1);
        scanf("%d", &(B+i)->minP1);
        printf ("Ingrese los minutos del 2do partido jugador %d \n", i+1);
        scanf("%d", &(B+i)->minP2);
        printf ("Ingrese los minutos del 3er partido jugador %d \n", i+1);
        scanf("%d", &(B+i)->minP3);
        fflush(stdin);
        sumapart = (B+i)->minP1 + (B+i)->minP2 + (B+i)->minP3;// se guarda la suma en una variable
        (B+i)->sumaT = sumapart; //se le asigan a un campo de direccion
    }
/*    printf ("MINUTOS: \n");
    for(i=0; i < 8; i++) {
        printf(" minutos 1er partido %d\n", (B+i)->minP1);
        printf(" minutos 2do partido %d\n", (B+i)->minP2);
        printf(" minutos 3er partido %d\n", (B+i)->minP3);
        printf(" minutos totales %d\n", (B+i)->sumaT);
    }*/    
} 
//ejer 2 terminado
void cantMinutos(equipo *A, tiempo *B) {
	//variables locales
	char jugadorX[20];
	int i, suma;

	printf("Ingrese el nombre del jugador:\n");
	fflush(stdin);
	scanf("%s", &jugadorX);//se guarda el nombre del jugador
	//inicio del ciclo para buscar al jugador X
	for(i=0; i<8; i++) {
		suma = 0;
		if (strcmp(jugadorX,(A+i)->nom ) == 0) {//se usa el metodo strcmp para comparar dos string, si es verdadero el resultado es 0
			if(((B+i)->sumaT) != 0) {
				printf(" Minutos jugados en el 1er tiempo es de: %d\n", (B+i)->minP1);
                printf(" Minutos jugados en el 2do tiempo es de: %d\n", (B+i)->minP2);
                printf(" Minutos jugados en el 3er tiempo es de: %d\n", (B+i)->minP3);
			}
			else { //falta verificar
				if(((B+i)->sumaT) == 0) {
					printf("El jugador %s no ha jugado ningun partido", jugadorX);
				}		
			}
		}
	}	
	
}

//ejer 3
void totalMin(equipo *I, tiempo *M) {
	//variables locales
	int i;
	char inicialN[1];
	char inicialA[1];
	//inicio del ciclo que recorre el vector
	for(i=0; i<8; i++) {
		strncpy(inicialN, (I+i)->nom, 1);  //se usa la funcion strcnpy para sacar el primer caracter del string
		strncpy(inicialA, (I+i)->ape, 1);
		printf("Jugador:\n", (M+i)->sumaT); 
		printf("%s ", inicialN);
		printf("%s.\n", inicialA);
		printf("El total de minutos jugados es de %d.\n", (M+i)->sumaT);
	
	}
}
//promedio terminado
void promedio(tiempo *M ) {
	int i, sumaTotal;
	float prom = 0;
	sumaTotal= 0;
	//se inicia un bucle para que recorra los campos de las direcciones que guardan los minutos por partido
	for(i=0; i<8; i++) {
		sumaTotal = sumaTotal + (M+i)->minP1 + (M+i)->minP2 + (M+i)->minP3;//REVISAR con sumat
	//	printf("la suma es de %d ", sumaTotal);
	}
	//en la variable prom se guarda el total de los minutos jugados
	prom = (float)sumaTotal / 2;
	printf("%f.\n", prom);//se muestra el resultado del promedio	
}

// ejercicio 4 terminado
void partidos(equipo *N, tiempo *T) {
    int i, numPartido;//variables locales
    
    do { //el bucle se repite tantas veces como el usuario ingrese una opcion dentro de las permitidas
        printf ("Partido numero 1:\n");
        printf ("Partido numero 2:\n");
        printf ("Partido numero 3:\n");
        printf ("Elija un partido:\n");
        scanf("%d", &numPartido);
        //el bucle inicia las operacion dependiende de la opcion que elija
        for(i=0; i<8; i++) {
        	//utilizo dos condiciones para limitar a la opcion seleccionada por el usuario dentro de los if
            if ( (((T+i)->sumaT) != 0) && (numPartido == 1 ) )  { 	
               printf ("Minutos jugados del jugador %s %s es \n", (N+i)->nom, (N+i)->ape);
               printf("1er partido %d\n", (T+i)->minP1);
            }
            else if ( (((T+i)->sumaT) != 0) && (numPartido == 2 ) )  {	
               printf ("Minutos jugados del jugador %s %s es \n", (N+i)->nom, (N+i)->ape);
               printf("1er partido %d\n", (T+i)->minP2);
		    }
			else {
				if ( (((T+i)->sumaT) != 0) && (numPartido == 3 ) )  {
				    printf ("Minutos jugados del jugador %s %s es \n", (N+i)->nom, (N+i)->ape);
                    printf("1er partido %d\n", (T+i)->minP3);	    
                }
			}
        }
    }while (numPartido <= 3);  //la condicion es que el numero ingresado sea menor o igual a 3, de lo contrario sale del bucle.
}
//ejer 5 terminado
void participantesSinJugar(equipo *P, tiempo *T) {
	int i, c; // variables locales
	c = 0; //la variable c es un contador
	//el bucle recorre los minutos de cada partido
	for(i=0; i<8; i++) {
		if(((T+i)->sumaT) == 0) { //la condicion es que la suma sea igual a 0
			printf ("%s %s \n", (P+i)->nom, (P+i)->ape);
		}
		else {
			c += 1; //el contador incremeta cuando la suma no es igual a 0
			if(c == 2) { 
				printf ("No se genera una lista\n");
				printf ("Todos participaron de los 3 partidos\n");
			}
		}
	}	
}
/*ejer 6 CORREGIR
void masMinJugados(equipo *P, tiempo *M, nombres *vecA) {
	int i, j;
	struct equipo aux;
	
	for(i=0; i < 8; i++) {
		if(((M+i)->sumaT) > ((M+i+1)->)) { 
	        aux = (vecA+i)->
			
		}	
	}
	for( j=0; j < 8; j++) {
		printf("Lista: \n");
		printf("%s, %s\n", (vecA+j)->n, (vecA+j)->a);
    }
} 
/*
void ordenamiento(equipo *P, tiempo *M, nombres *vecA){
	int i, j, aux, c;
	
	do {
		c = 0;
		for( i=0; i < 8-1; i++) {
    	    if( ( (M+i)->sumaT) < ((M+i+1)->sumaT) ) {
     	    	//se intercambian los nombres
    			strcpy( (vecA+i)->x, (vecA+i)->n );
     		    strcpy( (vecA+i)->n, (vecA+i)->n );
    			strcpy( (vecA+i+1)->n, (vecA+i)->x );
      			//se intercambian los apellidos
      		    strcpy( (vecA+i)->x, (vecA+i)->a );
    			strcpy( (vecA+i)->a, (vecA+i)->a );
    			strcpy( (vecA+i+1)->a, (vecA+i)->x );
	    		c += 1;	//en cada intercambio el contador incrementa 1			
	    	}	
    	}
		
	} while (c == 0);
	
	for( j=0; j < 6; j++) {
		printf("Lista: \n");
		printf("%s,  ", (vecA+j)->n);
		printf("%s\n", (vecA+j)->a);
    }
}*/

void listaJugadores(equipo *N, tiempo *T){
	int i;
	
	for( i=0; i < 23; i++) {
		if((T+i)->minP1 != 0) {
			printf("Primer partido: \n");
			printf("%s %s \n", (N+i)->nom, (N+i)->ape);
		} 
        if ( (T+i)->minP2 != 0)  {	
            printf("Segundo partido: \n");
			printf("%s %s \n", (N+i)->nom, (N+i)->ape);
	    }
		if ( (T+i)->minP3 != 0)  {
		    printf("Tercer partido: \n");
		    printf("%s %s \n", (N+i)->nom, (N+i)->ape);	    
        }
	}
}
