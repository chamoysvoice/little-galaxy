#include<iostream>
#include<string>
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