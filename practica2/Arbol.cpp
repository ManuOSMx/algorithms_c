
//LIBRERIAS INCLUIDAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//DEFINICION DE CONSTANTES DEL PROGRAMA

//DECLARACION DE ESTRUCTURAS
struct nodo{
	int dato;
	struct nodo *ptrizq;
	struct nodo *ptrder;
};

//DECLARACION DE FUNCIONES

struct nodo *nuevonodo(int dato1){ //Funcion para crear un nuevo nodo del arbol
	
	struct nodo *ptrAux;
	ptrAux = (struct nodo*) malloc (sizeof(struct nodo));
	ptrAux->dato=dato1;
	ptrAux->ptrizq = ptrAux->ptrder = NULL;
	return ptrAux;
};
//recibe apuntador a un nodo del arbo y clave que es el elemento a buscar 
//regresa el dato si se encontro o bien NULL si no fue encontrado 
struct nodo *buscarDato(struct nodo *ptr, int clave){ 
	if(ptr == NULL){
		
		return NULL;
	}
	else if(clave == ptr->dato)
		return ptr;
	else if(clave < ptr->dato)
		return buscarDato(ptr->ptrizq, clave);
	else
		return buscarDato(ptr->ptrder, clave);
};

void insertar(struct nodo **ptrRaiz, int miDato1){ //Funcion para insertar un dato
	if(*ptrRaiz==NULL)
	*ptrRaiz=nuevonodo(miDato1);
	else if(miDato1 < (*ptrRaiz)->dato)
		insertar(&((*ptrRaiz)->ptrizq), miDato1);
		else
			insertar(&((*ptrRaiz)->ptrder) ,miDato1);	
}

void preorden(struct nodo *ptrRaiz){ //Funcion para imprimir el arbol en Preorden
	if(ptrRaiz!=NULL){
		printf(" %d ", ptrRaiz->dato);
		preorden(ptrRaiz->ptrizq);
		preorden(ptrRaiz->ptrder);
	}
}

void inorden(struct nodo*ptrRaiz){ //Funcion para imprimir el arbol en Inorden
	if(ptrRaiz!=NULL){
		inorden(ptrRaiz->ptrizq);
		//printf(" %d ", ptrRaiz->dato);
		inorden(ptrRaiz->ptrder);
	}
}

void postorden(struct nodo *ptrRaiz){ //Funcion para imprimir el arbol en Postorden
	if(ptrRaiz!=NULL){
		postorden(ptrRaiz->ptrizq);
		postorden(ptrRaiz->ptrder);
		printf(" %d ", ptrRaiz->dato);
	}
}

void imprimirArbol(struct nodo *ptrRaiz, int contador){ //Funcion para imprimir el arbol entero
	int i,j;
	
	i= contador;
	if(ptrRaiz!=NULL){
		
		imprimirArbol(ptrRaiz->ptrder,i+1);
		printf("\n");
		
		for(j=1;j<i; j++)
			printf(" - ");
		
		printf("%d", ptrRaiz->dato);
		imprimirArbol(ptrRaiz->ptrizq, i+1);
		
	}
}

int max(int a, int b){ //Funcion para comparar numeros y ver cual es mayor
	if (a<b)
		return a;
	else 
		return b;
}

void eliminar(struct nodo **ptr, int clave){ //Funcion para eliminar un elemento del árbol
	if(*ptr == NULL)
		printf("\nLa clave no esta");
	else if(clave < (*ptr)->dato)
		eliminar(&(*ptr)->ptrizq, clave);
	else if(clave > (*ptr)->dato)
		eliminar(&(*ptr)->ptrder, clave);
	else{
		struct nodo *ptrAux;
		ptrAux = (*ptr);
		if(ptrAux->ptrizq == NULL)
			(*ptr) = ptrAux->ptrder;
		else if(ptrAux->ptrder == NULL)
			(*ptr) = ptrAux->ptrizq;
		else{
			struct nodo *ptrA, *ptrP;
			ptrP=ptrAux;
			ptrA=ptrAux->ptrizq;
			while(ptrA->ptrder){
				ptrP=ptrA;
				ptrA=ptrA->ptrder;
			}
			ptrAux->dato = ptrA->dato;
			if(ptrP == ptrAux)
				ptrP->ptrizq = ptrA->ptrizq;
			else
				ptrP->ptrder =ptrA->ptrizq;
				ptrAux=ptrA;
		}
		free(ptrAux);
	}
}

int profundidad(struct nodo *ptrRaiz){ //Funcion para imprimir la profundidad del árbol
	if(ptrRaiz!=NULL){
		if(ptrRaiz->ptrizq==NULL && ptrRaiz->ptrder==NULL)
			return 0;
		else
			return 1 + max(profundidad(ptrRaiz->ptrder), profundidad(ptrRaiz->ptrizq));	
	}
}

struct nodo *buscarDato(struct nodo *ptr, int clave); 




//PROGRAMA PRINCIPAL 
int main(int argc, char *argv[]){
	
	//Variables del main
	//char opc;
	//int clave; //Variable para guardar el dato de cada nodo
	//int maxi;
	//int numnodos=0;

	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medicion de tiempos
	struct nodo*miptrRaiz; //Creacion de apuntador miptrRaiz para empezar la creacion del arbol
	miptrRaiz=NULL; //Asignamos un valor NULL al apuntador
	int i=0,n, j; //i se utilizara para manejar el ciclo for 
	int B[]={3222486,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};
	int *A; //Arreglo dinamico donde se guardaran los n numeros
	n=atoi(argv[1]);
	A=(int*)malloc(sizeof(int)*n); //Creacion de memoria para el arreglo
	
	//for para leer los numeros y guardarlos en el arreglo dinamico
	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}

	//for para insertar los datos en el arbol binario
	for(i=0; i<n; i++){
		insertar(&miptrRaiz, A[i]);
	}

	struct nodo *numero;

	for(j=0; j<20; j++){

		utime0=0;
		stime0=0;
		wtime0=0;
		utime1=0;
		stime1=0;
		wtime1=0;

		uswtime(&utime0, &stime0, &wtime0); //Funcion para indicar el inicio del conteo de tiempo

		numero = buscarDato(miptrRaiz,B[j]);

		printf("---TIEMPO NUMERO %d---\n\n", B[j]);

		if(numero!=NULL){
			printf("El numero %d SI se encontro.", B[j]);
		}else{
			printf("El numero %d NO se encontro.", B[j]);
		}

		uswtime(&utime1, &stime1, &wtime1);//Funcion para indicar el termino del conteo de tiempo

		//Calculo del tiempo de ejecucion del programa
		printf("\n");
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciones de E/S)  %.10f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
		
		//Mostrar los tiempos en formato exponecial
		printf("\n");
		printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
	}

	

	//For que se encargara de realizar ciclos hasta que se seleccione la opción "salir"
	/*for(;;){
		int seleccion=menu(); //Variable que guardare el número de la selección del menú
		
		//Switch que servira para intercambiar entre selecciones
		switch(seleccion){
			
			//Caso en donde se crea un nuevo nodo y se guarda un dato en dicho nodo
			case 1:
				printf("\nIngrese un valor entero: ");
				scanf("%d", &clave);
				//getchar();
				insertar(&miptrRaiz, clave);
				printf("\n");
				break;
			
			case 2:
				imprimirArbol(miptrRaiz, 1);
				printf("\n");
				break;
			
			case 3:
				printf("\n PREORDEN \t");
				preorden(miptrRaiz);
				break;
			case 4:
				printf("\n INORDEN \t");
				inorden(miptrRaiz);
				break;
			
			case 5:
				printf("\n POSTORDEN \t");
				postorden(miptrRaiz);
				break;
			
			case 6:
				printf("La profundidad es: %d", profundidad(miptrRaiz));
				break;
				
			case 0:
				exit (0);
				break;
		}
	}*/
	return 0;
}
int menu(){ //Funcion que retorna el valor de la seleccion que el usuario quiere
	int seleccion;
	fflush(stdin);
	printf("\nArbol Binario");
	printf("\n1.- Insertar dato");
	printf("\n2.- Imprimir arbol");
	printf("\n3.- Preorden");
	printf("\n4.- Inorden");
	printf("\n5.- Postorden\n");
	printf("6.- Imprimir profundidad\n");
	printf("0.- Salir\n");
	
	scanf("%d", &seleccion);
	return seleccion;
}
