#include <stdio.h>
#include <stdlib.h>
#include "binarytree.c"

int main(){

	struct BinaryTree *bt = malloc(sizeof *bt);
	insertBT(bt,5);
	insertBT(bt,6);
	insertBT(bt,4);
	insertBT(bt,3);
	insertBT(bt,8);
	insertBT(bt,7);
	insertBT(bt,1);
	printTree(bt);
	searchBT(bt,4);

}
