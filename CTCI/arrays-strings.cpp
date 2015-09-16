#include<iostream>
#include<string>
#include<cctype>

/*
 * Problem source: "Cracking the Coding Interview" - 5ed - page: 73
 * Implement an algorithm to determine if a string has all unique characters. (1st part)
 * What if you cannot use additional data structures? (2nd part)
 */
bool isUnique(std::string s){
	unsigned short int frequency[256] = {0};
	for(int i = 0; i < s.length(); i++){
		frequency[s.at(i)]++;
		if(frequency[s.at(i)] >= 2){
			return false;
		}
	}
	return true;
}

bool isUniqueWOArray(std::string s){
	for(int i = 0; i < s.length(); i++){
		for(int j = i; j < s.length(); j++){
			if(isalpha(s.at(i)) && isalpha(s.at(j)) && s.at(i) == s.at(j)){
				return false;
			}
		}
	}
	return true;
}

/*
 * Another problem from that book, same page!
 */

char *reverseString(char* s){
	int length = strlen(s);
	char reverse[length];
	for(int i = length; i > 1; i--){
		reverse[length - i] = s[i];
	}
	reverse[length - 1] = '\0';
	return reverse;
}
