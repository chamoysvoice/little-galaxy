#include<iostream>
#include<string>

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