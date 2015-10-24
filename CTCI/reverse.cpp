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

void reverseInPlace(char *str){
	char *end = str;
	char t;
	// go back for last char
	while(*end != '\0'){
		end++;
	}
	end--;

	while(end > str){
		t = *end;
		*end-- = *str;
		*str++ = t;
	}
}

int main(){
    char s[SIZE] = "123456789";
    reverseInPlace(s);
    cout << "this is the value of s " << s;
}
