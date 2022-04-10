#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tiempo.h"



typedef struct node{
	struct node * l, * r;
	int value;
} node;

// [ izquierda, entra, derecha ] 
void in(node * n){
	
	if(n->l)in(n->l);
	if(n->r)in(n->r);
}

// crea un nuevo nodo & pone los nodos "origininales"
node * new(int value){
	node * n = malloc(sizeof(node));
	n->value = value;
	n->l = n->r = NULL;
	return n;
}

// Insercion recursiva
void insert(node ** root, node * child){
	
	if(!*root) *root = child;  // no existe
	
	else insert( child->value <= (*root)->value ? &(*root)->l : &(*root)->r , child );  // llamada recursiva
}

// busqueda recursiva de un nodo
node * search(node * root, int value){
	return !root ? NULL : root->value == value ? root : search( value > root->value ? root->r : root->l , value );
}

// guarda el resultado de una busqueda en un parametro tipo puntero
void searchByPointer(node * root, int value, node ** save){
	*save = search(root,value);
}


int main(int argc,char *argv[]){
	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos	
	int a,*arreglo,tam=atoi(argv[1]),cont=0;	
	node * root = NULL;
 	arreglo=malloc(sizeof(int)*tam);
	for(int i=0 ; i<tam; i++){
		scanf("%d",&a);
		insert(&root,new(a));//aqui se hace la generacion de numeros aleatorios y se insertan en el arbol
	}	
		
	// PRINT TEST
	uswtime(&utime0, &stime0, &wtime0);
	in(root);
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
	
}
