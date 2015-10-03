#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 12

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node Node;

int main(){
	int i;
	Node *root = (Node *)malloc(sizeof(Node));

	Node *t = root;

	for(i = 0; i < SIZE; i++){
		t->data = i;
		t->next = (Node *)malloc(sizeof(Node));
		t->next->prev = t;
		t = t->next;
	}

	for(; i >= 0; i--){
		t->data = i;
		t->next = (Node *)malloc(sizeof(Node));
		t->next->prev = t;
		t = t->next;
	}

	int palindrome = 1;

	Node *t2 = root;
	t = root;
	for( i = 0; i < SIZE; i++){
		t = t2 = t->next;
	}

	while(t && t2){
		printf("%d %d\n",t->data, t2->data);
		if(t->data == t2->data){
			t = t->next;
			t2 = t2->prev;
		} else {
			palindrome = 0;
			break;
		}
	}

	if(palindrome){
		printf("The linked list is a palindrome\n");
	} else {
		printf("The linked list is NOT a palindrome\n");
	}

	t = root;
	Node *clean;
	while (t){
		clean = t;
		t = t->next;
		free(t);
	}

}