#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int data;
}; 

typedef struct node Node;

struct stack{
	Node *min;
	Node *top;
};

typedef struct stack Stack;

bool c_push(Stack *stack, int data){
	Node *t;

	if((t = (Node *) malloc(sizeof(Node))) == NULL){
		puts("error on pop: malloc\n");
		return false;
	}

	t->data = data;

	if(!stack->top){
		stack->top = t;
	} else {
		t->prev = stack->top;
		stack->top = t;
	}

	if(!stack->min){
		stack->min = t;
	} else {
		if(stack->min->data >= t->data){
			stack->min = t;
		}
	}

	return true;
}

int c_pop(Stack *stack){
	if(!stack->top){
		puts("error pop: empty stack\n");
		return -1;
	}

	int t_data = stack->top->data;
	Node *t_node = stack->top;
	stack->top = t_node->prev;
	free(t_node);

	return t_data;
}

int c_min(Stack *stack){
	if(!stack->min){
		puts("error min: empty stack\n");
		return -1;
	}

	return stack -> min -> data;
}

int main(){
	Stack *s;
	if((s = (Stack *) malloc(sizeof(Stack))) == NULL){
		puts("Error main: stack malloc\n");
		return -1;
	}

	c_push(s, 5);
	c_push(s, 8);
	printf("min %d\n",c_min(s));
	printf("%d\n",c_pop(s));
	printf("%d\n",c_pop(s));

}