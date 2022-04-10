//CompilaciÃ³n: "g++ exponencial.cpp tiempo.c -o bexpo"
//EjecuciÃ³n: "./bexpo"

// C++ program to find an element x in a
// sorted array using Exponential search.
#include <bits/stdc++.h>
#include "tiempo.h"
using namespace std;

int busquedaBinaria(int arr[], int, int, int);

// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
	// If x is present at firt location itself
	if (arr[0] == x)
		return 0;

	// Find range for binary search by
	// repeated doubling
	int i = 1;
	while (i < n && arr[i] <= x)
		i = i*2;

	// Call binary search for the found range.
	return busquedaBinaria(arr, i/2,min(i, n-1), x);
}

int busquedaBinaria(int A[], int l,int r, int clave){
	int inicio=l;
	int final=r;
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

// Driver code
int main(int argc, char *argv[])
{
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

		printf("Numero: %d Posicion: %d\n", B[j], exponentialSearch(A,n,B[j]));

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

	return 0;
}
