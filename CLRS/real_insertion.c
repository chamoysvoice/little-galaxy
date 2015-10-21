void insertionSort(int *A, int n){
  if(n < 1){ // if n is 1, there is nothing to do
    return;
  }
  int i;
  int key;
  for(int j = 1; j < n; j++){
    i = j - 1;
    key = A[j];
    while(i >= 0 && A[i] > A[j]){
      A[i + 1] = A[i];
      i--;
    }
    A[i + 1] = key;
  }
}

int main(){}
