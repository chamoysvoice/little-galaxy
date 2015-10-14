#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define N 10

struct node{
  struct node *next;
  int data;
};

typedef struct node Node;

void recursiveInsertionSort(Node *root){
  if(!root->next){
    return;
  }

  recursiveInsertionSort(root->next);
  Node *t = root;
  int data;

  while(t->next){
    if(t->data > t->next->data){
      data = t->data;
      t->data = t->next->data;
      t->next->data = data;
    }
    t = t->next;
  }
  return;
}

int main(){
  Node *list = (Node *)malloc(sizeof(Node));
  Node *t = list;
  int i;
  srand(time(NULL));
  for(i = 0; i < N-1; i++){
    t->data = rand() % 20;
    t->next = (Node *)malloc(sizeof(Node));
    t = t->next;
  }
  t->data = rand() % 20;

  t = list;
  while(t){
    printf("%d ", t->data);
    t = t->next;
  }
  putchar('\n');

  recursiveInsertionSort(list);
  t = list;
  while(t){
    printf("%d ", t->data);
    t = t->next;
  }
  putchar('\n');
}
