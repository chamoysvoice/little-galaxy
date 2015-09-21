#include <iostream>

using namespace std;


/*
 * Book CTCI 5e problem 1.5;
 */

string compress(string s){
	string t = "";
	char l = s.at(0);
	int counter = 1;
	for(int i = 1; i < s.length(); i++){
		if(s.at(i) == l && i != s.length() - 1){
			counter++;
		} else{
			t += l + to_string(counter);
			l = s.at(i);
			counter = 1;
		}
	}
	return (t.length() < s.length())? t : s;
}

int main(){
	string s = "aaabbcccccee";
	string s2 = "absndba";
	string s3 = "ssaabss";

	cout << s << " to " << compress(s) << endl;
	cout << s2 << " to " << compress(s2) << endl;
	cout << s3 << " to " << compress(s3) << endl;

	return 0;
}