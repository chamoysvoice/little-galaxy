#include<stdio.h>
#define SIZE 100

/*
	This program is a simple Stack using pointers <3
*/

void push(int *a, int **p, int v){
	if(*p > a + SIZE){
		printf("Overflow - 1\n");
	}
	**p = v;
	*p += 1; 
}

int pop(int *a, int **p){
	if(*p <= a){
		printf("Underflow - 1\n");
		return -1;
	}
	*p -= 1;
	int x = **p;
	return x;
}

int main(){
	int a[SIZE];
	int *top = a;
	printf("%p\n", a);
	/*test overflow*/
	/*
	for(int i = 0; i < SIZE * 5; i++){
		push(a, &top, i);
	}
	*/
	push(a, &top, 3);
	printf("%d\n", pop(a, &top));
	printf("%d\n", pop(a, &top)); /*testing underflow*/
	return 0;
}