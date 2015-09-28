#include <iostream>
#define M 12
#define N 10
using namespace std;

/*
 * Fill the column and row of an element with value of zero with zeros.
 */

int main(){
	int matrix[M][N], temp_matrix[M][N];

	int c = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = c++;
			if(c == N + 9) {
				matrix[i][j] = 0;

			}
			temp_matrix[i][j] = matrix[i][j];
		}
	}


	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(matrix[i][j] == 0){
				for(int k = 0; k < M; k++){
					temp_matrix[k][j] = 0;
				} 
				for(int k = 0; k < N; k++){
					temp_matrix[i][k] = 0;
				}
			}
		} 
	} 


	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = temp_matrix[i][j];
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}