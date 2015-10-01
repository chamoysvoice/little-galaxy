#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_SIZE 100000
#define MAX_SIZE 1000000
#define CARRY 1
#define NO_CARRY 0
#define TEN 10
/* 
	Sum of N digits, yes please, bye bye overflow.
*/

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node Node;

int main(){
	
	const int NODE_SIZE = sizeof(Node);

	
	// Set up lists
	Node *list1, *list2, *result_list;
	
	if ((list1 = (Node*)malloc(NODE_SIZE)) == NULL){
		printf("Insuficient Memory\n");
		return -1;
	} 
	else if ((list2 = (Node*)malloc(NODE_SIZE)) == NULL){
		printf("Insuficient Memory\n");
		return -1;
	} 
	else if((result_list = (Node*)malloc(NODE_SIZE)) == NULL){
		printf("Insuficient Memory\n");
		return -1;
	}


	srand(time(NULL));

	int i, carry;
	int length_1, length_2;

	Node *t1 = list1, *t2 = list2, *t3 = result_list;
	
	length_1 = (rand() % (MAX_SIZE + 1 - MIN_SIZE)) + (MIN_SIZE);
	for(i = 0; i < length_1; i++){
		t1->data = rand() % TEN; 
		if((t1->next = (Node*)malloc(NODE_SIZE)) == NULL){
			printf("Insuficient Memory\n");
			return -1;
		}
		t1->next->prev = t1;
		t1 = t1->next;
		
	}


	length_2 = (rand() % (MAX_SIZE + 1 - MIN_SIZE)) + (MIN_SIZE);
	for(i = 0; i < length_2; i++){
		t2->data = rand() % TEN;
		if((t2->next = (Node*)malloc(NODE_SIZE)) == NULL){
			printf("Insuficient Memory\n");
			return -1;
		}
		t2->next->prev = t2;
		t2 = t2->next;
	}

	t1 = list1;
	t2 = list2;

	carry = NO_CARRY;

	while(length_1 && length_2){
		t3->data = ((t1->data + t2->data) + carry) % TEN;
		carry = (t1->data + t2->data >= TEN) ? CARRY : NO_CARRY;
		t1 = t1->next;
		t2 = t2->next;
		if((t3->next = (Node*)malloc(NODE_SIZE)) == NULL){
			printf("Insuficient Memory\n");
			return -1;
		}
		t3->next->prev = t3;
		t3 = t3->next;
		length_1--;
		length_2--;
	}

	while(t1->next || t2->next){
		if(length_1){
			t3->data = (t1->data + carry) % TEN;
			carry = (t1->data + carry == TEN)? CARRY : NO_CARRY;
			t1 = t1->next;
			length_1--;
		} else{

			t3->data = (t2->data + carry) % TEN;
			carry = (t2->data + carry == TEN)? CARRY : NO_CARRY;
			t2 = t2->next;
			length_2--;
		}
		
		if((t3->next = (Node*)malloc(NODE_SIZE)) == NULL){
			printf("Insuficient Memory\n");
			return -1;
		}
		t3->next->prev = t3;
		t3 = t3->next;
	}
	
	Node *clean;


	putchar('\n');
	while(t1 = t1->prev){
		printf("%d", t1->data );
		free(t1->next);
	} 
	
	puts("\n+");
	
	while(t2 = t2->prev){
		printf("%d", t2->data);
		free(t2->next);
	}

	puts("\n=");

	while(t3 = t3->prev){
		printf("%d", t3->data);
		free(t3->next);
	}

	puts("\n\n");
}