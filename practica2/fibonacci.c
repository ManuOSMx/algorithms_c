//Compilación: "gcc fibonacci.c tiempo.c -o bfib"
//Ejecución: "./bfib"

// C program for Fibonacci Search 
#include <stdio.h>
#include<stdlib.h>
#include "tiempo.h"

// Utility function to find minimum of two elements 
int min(int x, int y) { return (x<=y)? x : y; } 

/* Returns index of x if present, else returns -1 */
int fibMonaccianSearch(int arr[], int x, int n) 
{ 
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0; // (m-2)'th Fibonacci No. 
	int fibMMm1 = 1; // (m-1)'th Fibonacci No. 
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci 

	/* fibM is going to store the smallest Fibonacci 
	Number greater than or equal to n */
	while (fibM < n) 
	{ 
		fibMMm2 = fibMMm1; 
		fibMMm1 = fibM; 
		fibM = fibMMm2 + fibMMm1; 
	} 

	// Marks the eliminated range from front 
	int offset = -1; 

	/* while there are elements to be inspected. Note that 
	we compare arr[fibMm2] with x. When fibM becomes 1, 
	fibMm2 becomes 0 */
	while (fibM > 1) 
	{ 
		// Check if fibMm2 is a valid location 
		int i = min(offset+fibMMm2, n-1); 

		/* If x is greater than the value at index fibMm2, 
		cut the subarray array from offset to i */
		if (arr[i] < x) 
		{ 
			fibM = fibMMm1; 
			fibMMm1 = fibMMm2; 
			fibMMm2 = fibM - fibMMm1; 
			offset = i; 
		} 

		/* If x is greater than the value at index fibMm2, 
		cut the subarray after i+1 */
		else if (arr[i] > x) 
		{ 
			fibM = fibMMm2; 
			fibMMm1 = fibMMm1 - fibMMm2; 
			fibMMm2 = fibM - fibMMm1; 
		} 

		/* element found. return index */
		else return i; 
	} 

	/* comparing the last element with x */
	if(fibMMm1 && arr[offset+1]==x)return offset+1; 

	/*element not found. return -1 */
	return -1; 
} 

/* driver function */
int main(int argc, char *argv[]) 
{ 
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i=0, j=0, n; //La variable i se utiliza para el ciclo for, la k y la b para el control de los while y temp para el intercambio de posiciones
	int B[]={3322,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};
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

		printf("Numero: %d Posicion: %d\n", B[j], fibMonaccianSearch(A,B[j],n));

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
