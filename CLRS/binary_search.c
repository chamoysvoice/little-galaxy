#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define LENGTH 16
#define LOG_BASE 2
#define HALF 0.5
#define NOT_FOUND -1


/* O(log n) */
/* Needs an ordered array to work */
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


int main(){
  srand(time(NULL));

  int array[LENGTH];
  int search_for = rand() % (LENGTH * 2);
  int index;

  for(int i = 0; i < LENGTH; i++){
    array[i] = i * 2;
    printf("%d ", array[i]);
  }

  printf("\n search: %d\n", search_for);
  if((index = binarySearch(array, search_for)) != -1){
    printf("\nfound in index %d\n",index);
  } else {
    printf("\nelement not found\n");
  }
}
