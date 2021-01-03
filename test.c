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
	int popped = pop(l);
	printList(l);
	printf("Popped: %i \n",popped);
	return 0;

}
