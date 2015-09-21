#include <iostream>
#include <cctype>

using namespace std;

bool checkIfPermutation(string a, string b){
	unsigned char freq_a[256] = {0}, freq_b[256] = {0}; 

	for(int i = 0; i < a.length(); i++){
		if(isalpha(a.at(i))) freq_a[a.at(i)] += 1;
	}

	for(int i = 0; i < b.length(); i++){
		if(isalpha(b.at(i))) freq_b[b.at(i)] += 1;
	}

	for (int i = 0; i < 256; i++){
		if(freq_a[i] != freq_b[i]) return false;
	}
	return true;
}

int main(){
	string a = "te st";
	string b = " ts  et";

	cout << checkIfPermutation(a, b) << endl;
	return 0;
}