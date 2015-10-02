#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define LOOPHEAD 3

struct node {
	int data;
	struct node *next;
};

typedef struct node Node;

int main() {
	Node *root = (Node *)malloc(sizeof(Node));

	Node *t = root, *loop;
	int i;
	t->data = 0;
	for(i = 1; i < SIZE; i++){
		t->next = (Node *)malloc(sizeof(Node));
		t = t->next;
		t->data = i;
	}	

	t = root;


	while(t->next){
		if(t->data == LOOPHEAD){
			loop = t;
		}
		t = t->next;
	}
	t->next = loop;



	t = root;
	for(i = 0; i < SIZE * 10; i++){
		printf("%d\n", t->data);
		if(t > t->next){
			loop = t->next;
		}
		t = t->next;
	}

	printf("The looped element is %d\n", loop->data);
}


