#include <stdio.h>
#include <stdlib.h>
//We call them NodeBT to make them compatible with linkedlist library
struct NodeBT{

	struct NodeBT *parent;
	struct NodeBT *leftNode;
	struct NodeBT *rightNode;
	int value;

};
struct BinaryTree {

	struct NodeBT *root;

};

//Recursive function to insert
void insertR(struct NodeBT *currentNode, int value){

	if(currentNode->value == value){
		printf("You cannot insert repeated keys!");
	}
	if(value < currentNode->value){
		if(currentNode->leftNode != NULL){
			insertR(currentNode->leftNode,value);
		}else{
			struct NodeBT *newNode = malloc(sizeof *newNode);
			newNode->value = value;
			currentNode->leftNode = newNode;
		}
	}else{
		if(currentNode->rightNode != NULL){
			insertR(currentNode->rightNode,value);
		}else{
			struct NodeBT *newNode = malloc(sizeof *newNode);
			newNode->value = value;
			currentNode->rightNode = newNode;
		}
	}


}


//Wrapper function
void insertBT(struct BinaryTree *bt, int value){

	//Insert the root
	if(bt->root == NULL){
		struct NodeBT *newRoot = malloc(sizeof *newRoot);
		bt->root = newRoot;
	}else{
		insertR(bt->root,value);
	}
}

