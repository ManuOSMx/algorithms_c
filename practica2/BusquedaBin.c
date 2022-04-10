
//Medición de tiempo de Algoritmo de Busqueda Binaria 
//Compilación: "gcc BusquedaBin.c tiempo.c -o bin"
//Ejecución: "./bin" (Linux)
//compliación opción 2: ./InstruccionesB.bash
//

//LIBRERIAS INCLUIDAS
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "tiempo.h"
/*
La función recibe el arreglo A donde se encuentran todos los numeros sobre los que se realizara la busqueda
recibe n que es el tamaño del arreglo y recibe clave que es el numero a buscar
Regresa -1 si el numero no fue encontrado o bien el numero que se encontro
*/
int busquedaBinaria(int A[], int n, int clave);
//DEFINICIÓN DE CONSTANTES


//PROGRAMA PRINCIPAL
int main(int argc, char *argv[]){

	//Variables del main
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i=0, j=0, n; //La variable i se utiliza para el ciclo for, la k y la b para el control de los while y temp para el intercambio de posiciones
	int B[]={322486,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};
	int *A; //Arreglo dinámico donde se guardaran los n numeros
	n=atoi(argv[1]);
	A=(int*)malloc(sizeof(int)*n); //Creación de memoria para el arreglo

	//for para leer los numeros y guardarlos en el arreglo dinámico
	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	
	
	for(j=0; j<20; j++){

		utime0=0;
		stime0=0; 
		wtime0=0; 
		utime1=0; 
		stime1=0; 
		wtime1=0;

		uswtime(&utime0, &stime0, &wtime0); //Función para indicar el inicio del conteo de tiempo

		printf("Numero: %d Posicion: %d\n", B[j], busquedaBinaria(A,n,B[j]));

		uswtime(&utime1, &stime1, &wtime1); //Funcion para indicar el termino el conteo de tiempo

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
	
	


	/*for(i=0; i<n; i++){
		printf("%d\n", i+1, A[i]);
	}*/

	return 0;

}
/*Funcion para la busqueda de cada numero 
la busqueda binaria funciona, marcando el punto medio de arreglo donde se busca el numero, luego , si el numero  a buscar
es mayor entonces el punto de inicio par buscar de recorre a la mitad del arreglo y se obtiene un nuevo punto medio
si este es menor, el final se recorre hasta el punto medio y se obtiene una nueva mitad, y así hasta que el 
numero medio coincida con el numero a buscar 

Esta función regresa un -1 si el número no fue encontrado, de lo contrario regresa el numero encontrado.
*/
int busquedaBinaria(int A[], int n, int clave){
	int inicio=0;
	int final=n;
	int medio;
	while(inicio<=final){ 
		medio= (inicio + final)/2;
		if(A[medio]==clave){
			return medio;
		}else{
			if(clave<A[medio]){
				final = medio-1;
			}else{
				inicio = medio+1;
			}
		}
	}
	return -1;
}
