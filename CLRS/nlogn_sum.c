#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define LENGTH 10
#define LOG_BASE 2
#define HALF 0.5
#define NOT_FOUND -1

/*
Describe a (n lg n)-time algorithm that, given a set S of n integers and another
integer x, determines whether or not there exist two elements in S whose sum is
exactly x.
*/

int binarySearch(int *A, int value){
  int i = LENGTH / 2;
  for(int j = 1; j <= log(LENGTH) / log(LOG_BASE); j++){
    if(value == A[i]){
      return i;
    } else if(value < A[i]){
      i -= LENGTH * pow(HALF, j + 1);
    } else if(value > A[i]){
      i += LENGTH * pow(HALF, j + 1);
    }
  }
  return NOT_FOUND;
}

int isThereASum(int *A, int value){
  for(int i = 0; i < LENGTH; i++){
    if(value - A[i] != A[i] && binarySearch(A, value - A[i]) != NOT_FOUND){
      return TRUE;
    }
  }
  return FALSE;
}

int main(){
  int array[LENGTH] = {1, 3, 5, 7, 8, 10, 11, 13, 20, 22};
  if(isThereASum(array, 28)){ // expected to be true
    printf("There are two elements that added sum 28\n");
  }
  if(isThereASum(array, 3)){  // expected to be false
    printf("There are two elements that added sum 3\n");
  }
  if(isThereASum(array, 42)){ // expected to be true
    printf("There are two elements that added sum 42\n");
  }
}
