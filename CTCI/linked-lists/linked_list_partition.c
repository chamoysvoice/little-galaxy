#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


struct node{
	int data;
	struct node *next;
};

typedef struct node Node;

int main(){
	Node *root = (Node *)malloc(sizeof(Node));

	Node *partitions = (Node *)malloc(sizeof(Node));

	srand(time(NULL)); 

	int i, x = rand() % 10;

	printf("x = %d \n ==========\n", x);

	Node *t = root;
	Node *p = partitions;
	t->data = rand() % 10;
	p->data = 0;
	for(i = 0; i < N - 1; i++){
		t->next = (Node *)malloc(sizeof(Node));
		t = t->next;
		t->data = rand() % 10;	
		p->next = (Node *)malloc(sizeof(Node));
		p = p->next;
		p->data = 0;
	}

	t = root;
	p = partitions;

	while(t){
		if(t->data <= x){
			p->data = t->data;
			p = p->next;
		}
		t = t->next;
	}

	t = root;
	
	while(t){
		if(t->data > x){
			p->data = t->data;
			p = p->next;
		}
		t = t->next;
	}	

	t = root;

	while(t){
		printf("%d\n", t->data);
		t = t->next;
	}

	putchar('\n'); 

	p = partitions;
	while(p){
		printf("%d\n", p->data);
		p = p->next;
	}
}