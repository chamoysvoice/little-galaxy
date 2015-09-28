#include <iostream>
#include <math.h>
#define N 5

using namespace std;

/*
 *  Rotate a matrix 90 degrees
 */

int main(){
	int matrix[N][N];

	int c = 0, temp, n;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = c++;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	n = N - 1;


	cout << endl << endl; 
	for(int i= 0; i < floor(N / 2.0); i++){
		for(int j = 0; j < ceil(N / 2.0); j++){
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][n - i];
			matrix[j][n - i] = matrix[n - i][n - j];
			matrix[n - i][n - j] = matrix[n - j][i];
			matrix[n - j][i] = temp;	
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}