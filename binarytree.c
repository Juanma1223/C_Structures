#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"
//We call them NodeBT to make them compatible with linkedlist library
struct NodeBT{

	struct NodeBT *parent;
	struct NodeBT *leftNode;
	struct NodeBT *rightNode;
	int value;

};
//BinaryTree can be implemented with just nodes
//The reason for this implementation is to keep track of roots and to make the structures a bit easier to understand
//This involves the usage of wrapper functions to access root's node pointer
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
		newRoot->value = value;
		bt->root = newRoot;
	}else{
		insertR(bt->root,value);
	}
}

//Recursive function to print the tree
void printTreeR(struct NodeBT *currentNode, struct LinkedList *l){

	//Add the root first
	add(l,currentNode->value);
	if(currentNode->leftNode != NULL){
		printTreeR(currentNode->leftNode,l);
	}
	if(currentNode->rightNode != NULL){
		printTreeR(currentNode->rightNode,l);
	}

}
//Wrapper function for the real recursive function
void printTree(struct BinaryTree *bt){

	//List to hold the values
	struct LinkedList *l = malloc(sizeof *l);
	printTreeR(bt->root,l);
	printList(l);

}

int searchR(struct NodeBT *currentNode, int value){

	if(currentNode->value == value){

		return 1;

	}else{
		if(value < currentNode->value){
			if(currentNode->leftNode != NULL){
				return searchR(currentNode->leftNode,value);
			}
		}else{
			if(currentNode->rightNode != NULL){
				return searchR(currentNode->rightNode,value);
			}
		}
	}

	return 0;

}

//Wrapper function for the real recursive search
void searchBT(struct BinaryTree *bt, int value){

	int found = searchR(bt->root,value);
	if(found == 1){
		printf("True \n");
	}else{
		printf("False \n");
	}

}
