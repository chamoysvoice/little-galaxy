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

	struct node *t = root;
	int i;

	struct node *t2;

	srand(time(NULL));


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

	putchar('\n');
	
	t = root;

	struct node* cleaner;

	while(t){
		t2 = t;
		while(t2->next){
			if(t2->next->data == t->data){
				printf("%d duplicated content %d \n", t2->next->data, t->data); 
				if(t2->next->next){
					cleaner = t2->next;
					t2->next = t2->next->next;
					free(cleaner);
				}
				else {
					free(t2->next);
				}
			}
			t2 = t2->next;
		}


		t = t->next;
	}

	putchar('\n');

	t = root;

	while(t){
		printf("%d\n", t->data);
		t = t->next;
	}

}