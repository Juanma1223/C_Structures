#include <stdio.h>
#include <stdlib.h>
struct Node{

	int value;
	struct Node *nextNode;

};

struct LinkedList{

	struct Node *head;
	struct Node *tail;

};

void add(struct LinkedList *l,int value){

	struct Node *newNode = malloc(sizeof *newNode);
	newNode->value = value;
	newNode->nextNode = l->head;
	l->head = newNode;

}

void  printList(struct LinkedList *l){

	struct Node *currentNode = l->head;
	printf("[");
	while(currentNode != NULL){
		printf("%i,",currentNode->value);
		currentNode = currentNode->nextNode;
	}
	printf("] \n");

}

//Insertar en una posicion determinada de la lista
void insert(struct LinkedList *l,int pos, int value){


	struct Node *newNode = malloc(sizeof *newNode);
	newNode->value = value;
	//Contador para llegar a la posicion
	struct Node *currentNode = l->head;
	//Recorremos la lista hasta llegar a la posicion deseada
	int i = 0;
	//Tenemos un puntero al nodo anterior para enlazar el nodo que estamos insertando
	struct Node *prev;
	while(i < pos){

		prev = currentNode;
		currentNode = currentNode->nextNode;
		i = i + 1;

	}
	//Modificamos la estructura
	prev->nextNode = newNode;
	newNode->nextNode = currentNode;

}

//Funcionalidades de pila y cola
int pop(struct LinkedList *l){

	struct Node *head = l->head;
	int value = head->value;
	struct Node *next = head->nextNode;
	l->head = next;
	return value;

}

