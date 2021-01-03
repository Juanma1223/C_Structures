#include <stdio.h>
//In case your C version does not implement INFINITY constant
#define INFINITY 9999999

//Simple sorting algorithm O(n**2), better implement quicksort or mergesort for O(nlog(n)) complexity
void sort(int *a, int size){
	
	int min = INFINITY;
	int aux;
	int minPosition;
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(a[j] < min){
				min = a[j];
				minPosition = j;
			}
		}
	aux = a[i];
	a[i] = min;
	a[minPosition] = aux;
	min = INFINITY;
	}
}

//Function that prints the content of an array of numbers
void printA(int *a,int size){

	printf("Array: [");

	for(int i=0;i<size;i++){
		printf("%i,",a[i]);
	}
	printf("] \n");

}
