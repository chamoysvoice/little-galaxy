#include <stdio.h>
#include <assert.h>

int binarySearch(int *a, int element, int s, int e){
  if(s > e){
    return -1;
  }
  if(s == e){
    return -1;
  }
  if(a[(s + e) / 2] == element){
    return (s + e) / 2;
  } else if(a[(s + e) / 2] < element){
    return binarySearch(a, element, s, ((s + e) / 2));
  } else {
    return binarySearch(a, element, (s + e) / 2 + 1, e);
  }
}

int main(){
  int a[10] = {1, 3, 5, 5, 6, 9, 12, 30, 43, 54};

  int i;
  for (i = 1; i < 100; i++){
    printf("%d ", binarySearch(a, i, 0, 9));
  }
}
