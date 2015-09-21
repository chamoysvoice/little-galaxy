#include <iostream>

using namespace std;

/*
Book CTCI 5e problem 1.4;
*/

int countNonSpace(string a){
	int counter = 0;
	for(int i = 0; i < a.length(); i++){
		if(a.at(i) != ' '){
			counter++;
		}
	}	

	return counter;
}

int countSpace(string a){
	int counter = 0;
	bool prevSpace = false;

	for(int i = 0; i < a.length(); i++ ){
		if(a.at(i) == ' ' && prevSpace == false){
			counter++;
			prevSpace = true;
		} else if (prevSpace == true && a.at(i) != ' '){
			prevSpace = false;
		}
	}

	return counter;
}

string trimSpaces(string a){
	bool prevSpace = false;
	string temp = "";

	for(int i = 0; i < a.length(); i++){
		if(a.at(i) != ' '){
			prevSpace = false;
			temp += a.at(i);
		} else if(!prevSpace){
			temp += "%20";
			prevSpace = true;
		}
	}

	return temp;
}

int main(void){

	string a = "This is a   test";

	cout << "Caracteres " << trimSpaces(a) << endl;
	return 0;
}