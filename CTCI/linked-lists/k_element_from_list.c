#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


struct node {
	struct node *next;
	int data;
};


int main(){
	struct node *root = (struct node*) malloc(sizeof(struct node));

	struct node *t = root, *element;
	int i;



	struct node *t2;

	srand(time(NULL));

	int counter = 0, k = 4, counter2; //ejemplo

	t->data = rand() % 10;
	for(i = 0; i < N - 1 ; i++){
		t->next = (struct node*) malloc(sizeof(struct node));
		t = t->next;
		t->data = rand() % 10;
	}

	t = root;

	while(t){
		printf("%d\n", t->data);
		t = t->next;
	}

	t = root;

	while(t){
		counter++;
		t = t->next;
	}

	t = root;
	while(t){
		counter--;
		if(counter == k - 1){
			element = t;
		}

		t = t->next;
	}

	printf("\n\n%d\n", element->data);
}