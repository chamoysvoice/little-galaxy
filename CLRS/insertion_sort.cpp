#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <climits>
#define SIZE 20
#define RANGE 100

void insertionSort(std::vector<int> a){
	int min, position, temp;
	for(int i = 0; i < a.size(); i++){
		min = INT_MAX;
		for (int j = i; j < a.size(); j++){
			if(min > a.at(j)){
				min = a.at(j);
				position = j;
			}
		}
		temp = a.at(i);
		a.at(i) = a.at(position);
		a.at(position) = temp;
	}

	for(int i = 0; i < a.size(); i++){
		std::cout << a.at(i) << std::endl;
	}
}


int main (){
	srand(time(NULL));

	std::vector<int> a;
	for(int i = 0; i < SIZE; i++){
		a.push_back(rand() % RANGE + 1);
	}

	insertionSort(a);
	return 0;
}