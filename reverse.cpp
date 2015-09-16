#include <iostream>
#include <cstring>
#define SIZE 10

using namespace std;

void reverseString(char* s, char* r){
	int length = strlen(s);
	int j = 0;
	for(int i = length - 1; i >=0; i--){ 
		r[j] = s[i];
		j++;	
	}
}

int main(){
    char s[SIZE] = "123456789", r[SIZE];
    reverseString(s, r);
    cout << "this is the value of r " << r;
}
