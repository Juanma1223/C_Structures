#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

int main(){

	struct LinkedList *l = malloc(sizeof *l);
	add(l,8);
	add(l,1);
	add(l,3);
	insert(l,1,7);
	printList(l);
	int length = l->length;
	printf("Length: %i \n",l->length);
	int popped = pop(l);
	printList(l);
	printf("Length: %i \n",l->length);
	int curTail = l->tail->value;
	printf("Current tail: %i \n",curTail);
	printf("Popped: %i \n",popped);
	printf("Dequeued: %i \n",dequeue(l));
	printList(l);
	return 0;

}
