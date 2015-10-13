#include <stdio.h>
#include <stdlib.h>
#define NOT_BALANCED -1
#define NULL_NODE 0
#define STEP 1

struct node {
  struct node *right;
  struct node *left;
  int data;
};

typedef struct node Node;

int isBalanced(Node *root){
  if(!root){
    return NULL_NODE;
  }
  
  int l,r;
  l = isBalanced(root->left);
  r = isBalanced(root->right);
  if(l == NOT_BALANCED || r == NOT_BALANCED || abs(l - r) > 1){
    return NOT_BALANCED;
  } else if(l > r){
    return l + STEP;
  }
  return r + STEP;
}

void createBalancedTree(Node *root){
  if(!root){
    root = (Node *)malloc(sizeof(Node));
  }
  // make a (Balanced) tree
  root->right = (Node *)malloc(sizeof(Node));
  root->left = (Node *)malloc(sizeof(Node));
  root->right->right = (Node *)malloc(sizeof(Node));
  root->right->left = (Node *)malloc(sizeof(Node));
  root->left->left = (Node *)malloc(sizeof(Node));
}

void createUnbalancedTree(Node *root){
  if(!root){
    root = (Node *)malloc(sizeof(Node));
  }
  //make a (Unbalanced) tree
  root->right = (Node *)malloc(sizeof(Node));
  root->left = (Node *)malloc(sizeof(Node));
  root->right->left = (Node *)malloc(sizeof(Node));
  root->right->left->right = (Node *)malloc(sizeof(Node));
  root->right->left->right->left = (Node *)malloc(sizeof(Node));
}

void runTests(){
  Node *tree1 = (Node *)malloc(sizeof(Node));
  createBalancedTree(tree1);
  if(isBalanced(tree1) == NOT_BALANCED){
    printf("The tree 1 is not balanced\n");
  } else {
    printf("The tree 1 is balanced\n");
  }

  Node *tree2 = (Node *)malloc(sizeof(Node));
  createUnbalancedTree(tree2);
  if(isBalanced(tree2) == NOT_BALANCED){
    printf("The tree 2 is not balanced\n");
  } else {
    printf("The tree 2 is balanced\n");
  }
  printf("int returned by isBalanced(Node *root):\ntree 1:%d\ntree 2:%d\n", isBalanced(tree1), isBalanced(tree2));
}

int main(){
  runTests();
}
