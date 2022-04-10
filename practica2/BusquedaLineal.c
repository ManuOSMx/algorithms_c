
//Medición de tiempo de Algoritmo de busqueda lineal
//Compilación: "gcc BusquedaLineal.c tiempo.c -o lineal"
//Ejecución: "./lineal" (Linux)
//compliación opción 2: ./InstruccionesL.bash
//

//LIBRERIAS INCLUIDAS
#include<stdio.h>
#include<stdlib.h>
#include "tiempo.h"


int main(int argc, char *argv[]){

	int i=0, j=0,n; //variables auxiliares para los ciclos 
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	char band= 0; //esta variable es un indicador en la busqueda 
	int B[20]={322486,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};
	int *A; //Arreglo dinámico donde se guardaran los n numeros del archivo
	n=atoi(argv[1]);
	A=(int*)malloc(sizeof(int)*n); //Creación de memoria para el arreglo
	//llenamos el arreglos de numeros 
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}

	//algoritmo de busqueda lineal

	for(j=0; j<20;j++){

		utime0=0;
		stime0=0; 
		wtime0=0; 
		utime1=0; 
		stime1=0; 
		wtime1=0;
		band=0;

		uswtime(&utime0, &stime0, &wtime0); //Función para indicar el inicio del conteo de tiempo
		//*******BUSQUEDA LINEAL *******
		//esta función regresa un uno si el numero ha sido encontrado, así como la posición del mismo 

		for(i=0;i<n;i++){
			if(A[i]==B[j]){ //se hace una comparacion del numero a buscar con cada posicion de arreglo A
				printf("El numero %d esta en la posicion %d \n", B[j], i );
				band=1; //si se cumple la condicion, la bandera cambia, lo que indica que el numero ha sido encontrado
			}
		}
		if(band==0){ //si la bandera sigue siendo 0 quiere decir que el numero no se ha encontrado
			printf("El numero %d no esta \n", B[j] );
		}

		uswtime(&utime1, &stime1, &wtime1); //fin del conteo de tiempo

		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("---NUMERO %d---\n\n", B[j]);
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
		
		//Mostrar los tiempos en formato exponecial
		printf("\n");
		printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
		printf("\n");
	}
	
	return 0;

}
