//Medición de tiempo de Algoritmo de Busqueda exponencial con Hilos
//Compilación: "gcc BusquedaExpoHilos.c tiempo.c -o hilo -lpthread"
//Ejecución: "./hilo" (Linux)
//
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;	//Número de threads
int N,j;
int *A;	//Arreglo dinámico donde se guardaran los n numeros del archivo
int B[]={322486,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};


//funcion para obtener un subarreglo
void subarray(int a[],int i,int n,int sa[]){
	int iaux,cont=0;
	for(iaux=i;iaux<i+n;iaux++){
		sa[cont] = a[iaux];
		cont++;
	}
}
/*
La funcion procesar indica a cada hilo en que intervalo del arreglo de numeros va a trabajar
podemos observar que recibimos el numero de hilo, el tamaño del problema y el numero de hilos
con estas variables, indicamos el inicio y el fin del inttervalo con el que cada hilo va a trabajar
Recibe el numero de hilo con el que se está trabajando
*/
void* procesar(void* id)
{	
	int n_thread=(int)id;
	int inicio,fin,nE;

	//Aqui se indica a cada hilo el intervalo de numeros con el que va a trabajar
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1){	
		fin=N;
		nE = fin-inicio;
	}
	else{
		fin=((n_thread+1)*N)/NumThreads-1;
		nE = (fin-inicio)+1;
	}

	printf("\nThread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);
	//luego de saber el inicio y fin del intervalo con el que trabajara el hilo, se llama a la funcion de busqueda
	
	int *sa = (int*)malloc(nE*sizeof(int));
	subarray(A,inicio,nE,sa);
	if(exponentialSearch(sa,nE,B[j])!=-1){
		printf("    ++El numero %d si se encontro.", B[j]);
	}
	
	if(n_thread!=0){
		pthread_exit(0); //Termina el hilo, a excepcion del main.
	}
	  
}

//********************************************************************************
//DECLARACION DE FUNCIONES
/*la función recibe el arreglo A donde se buscaran los numeros, el inicio de este arreglo,el final, que nos ayudan 
a saber en que intervalo se realizara la busqueda del numero 
y la clave que es el numero que se va a buscar
*/

int busquedaBinaria(int arr[], int, int, int);
int exponentialSearch(int arr[], int n, int x);
int min(int a,int b);

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i=0; //Variables auxiliares para loops
	
	//********************************************************************************
	//Obtener el número de threads a usar y el arreglo para la identificacion de los mismos
	//********************************************************************************
	pthread_t *thread;
	if (argc<2) 
	{
		printf("Indique el número de threads - \tEjemplo: [user@equipo]$ %s4\n\n",argv[0]);
		exit(-1);
	}  
	NumThreads=atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));

	
	//Obtenemos tamaño del problema N
	if (argc!=3) 
	{
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[2]);

	A=(int*)malloc(sizeof(int)*N); //Creación de memoria para el arreglo
	//ciclo para llenar el arreglo con el tamaño del problema 
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	i=0;
	//ciclo  para la busqueda de cada numero
	for(j=0; j<20; j++){

		double utime0=0, stime0=0, wtime0=0, utime1=0, stime1=0, wtime1=0;

		uswtime(&utime0, &stime0, &wtime0); //inicio del conteo de tiempo 

		printf("----------TIEMPO NUMERO: %d ----------\n", B[j]);

		//Crear los threads con el comportamiento "procesar"
		//ciclo para enviar cada hilo a la funcion procesar 
		for (i=1; i<NumThreads; i++) 
		{	 
			if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
			{
				perror("El thread no pudo crearse");
				exit(-1);
			}
		}
		procesar(0);
		
		//Esperar a que terminen los threads (Procesar)
		for (i=1; i<NumThreads; i++){
				pthread_join(thread[i], NULL); //esta funcion nos permite separar los hilos
			} 	

		uswtime(&utime1, &stime1, &wtime1); //termino del conteo de tiempo 
		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
		printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
		printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");

	}
	
	//Terminar programa normalmente	*/
	exit (0);	
}
/*funcion para la busqueda de un numero 
La función regresa un -1 si el numero no se encontro o bien regresa el número en caso de ser encontrado
*/
int min(int a,int b){
	if(a>b)
		return b;
	else
		return a;
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


