#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"
#include "binarytree.c"

int main(){

	struct BinaryTree *bt = malloc(sizeof *bt);
	insertBT(bt,5);
	insertBT(bt,6);
	insertBT(bt,4);

}
