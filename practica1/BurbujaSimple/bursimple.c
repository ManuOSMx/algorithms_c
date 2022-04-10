//LIBRERIAS BURBUJA SIMPLE
#include<stdio.h>
#include<stdlib.h>
#include "tiempo.h"
/*
Funcion burbuja
Recibe un arreglo de numero y el tamaño de este arreglo.
Acomoda de menor a mayo el arreglo de numeros.
*/
void burbuja(int arreglo[],int tam)
{ 
	int aux;
	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j <tam-1; ++j)
		{
			//printf("%d.-arreglo[%d]>arreglo[%d]\n",i,arreglo[j],arreglo[j+1]);
			if (arreglo[j]>arreglo[j+1])
			{ //Compara y ordena segun la jerarquia del numero
				aux=arreglo[j];
				arreglo[j]=arreglo[j+1]; 
				arreglo[j+1]=aux;
		}
			}
			
	}
	
}
int main (int argc,char *argv[]){
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int tam,*arreglo;
	tam=atoi(argv[1]);
	arreglo=malloc(sizeof(int)*tam);
	for(int i=0;i<tam;++i)
		{	//Se Introducen datos al arreglo
		scanf("%d",&arreglo[i]);
	} 
	uswtime(&utime0, &stime0, &wtime0);
	burbuja(arreglo,tam);
	uswtime(&utime1, &stime1, &wtime1);
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - 	wtime0));
	/*for (int i = 0; i < tam; ++i)
	{ 	//Imprime el arreglo acomodado
		printf("\narreglo[%d]=%d",i+1,arreglo[i]);
	}*/
	printf("\n");
	return 0;
}
