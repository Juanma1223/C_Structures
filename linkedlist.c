#include <stdio.h>
#include <stdlib.h>
struct Node{

	int value;
	struct Node *nextNode;
	struct Node *prevNode;

};

struct LinkedList{

	struct Node *head;
	struct Node *tail;
	//Keep the length in O(1) complexity
	int length;

};

void add(struct LinkedList *l,int value){

	struct Node *newNode = malloc(sizeof *newNode);
	newNode->value = value;
	newNode->nextNode = l->head;
	if(l->head == NULL){
		//In case our list has only one node
		l->tail = newNode;
		l->length = 0;
		l->head = newNode;
	}else{
		l->head->prevNode = newNode;
		l->head = newNode;
	}
	//Increase list's length
	l->length = l->length+1;

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

//Insert a value in a certain position
void insert(struct LinkedList *l,int pos, int value){


	struct Node *newNode = malloc(sizeof *newNode);
	newNode->value = value;
	//Keep track of the position
	struct Node *currentNode = l->head;
	int i = 0;
	//Keep a pointer for the previous node to link the new one
	struct Node *prev;
	while(i < pos){

		prev = currentNode;
		currentNode = currentNode->nextNode;
		i = i + 1;

	}
	//Insert the node inbetween
	prev->nextNode = newNode;
	newNode->prevNode = prev;
	newNode->nextNode = currentNode;
	l->length = l->length+1;

}

//Stack and Queue functions
int pop(struct LinkedList *l){

	if(l->head == NULL){return NULL;}
	struct Node *head = l->head;
	int value = head->value;
	struct Node *next = head->nextNode;
	l->head = next;
	l->length = l->length-1;
	return value;

}

int dequeue(struct LinkedList *l){

	if(l->head == NULL){return NULL;}
	int tailValue = l->tail->value;
	struct Node *prev = l->tail->prevNode;
	prev->nextNode = NULL;
	l->tail = prev;
	return tailValue;

}



