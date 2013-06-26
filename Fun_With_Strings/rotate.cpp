// Rotates an image represented by M by 90 degrees 
// counterclockwise. We assume that each pixel is 
// 4 bytes (an int) in size.

#include <iostream>
using namespace std;

void rotate(int **M, int N){
	int beg, end, t;
	for(int i=0;i<N;i++){
		beg = 0;
		end = N-1;
		while(end > beg){
			t = M[i][end];
			M[i][end] = M[i][beg];
			M[i][beg] = t;
			end -= 1;
			beg += 1;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			t = M[j][i];
			M[j][i] = M[i][j];
			M[i][j] = t;
		}
	}
}

void printMatrix(int ** M, int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void test(){
	int N = 3;

	int **M;
	M = new int *[10];
	for(int i = 0; i <10; i++)
    	M[i] = new int[10];
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		M[i][j] = i*N + j;
    	}
    }

	printMatrix(M,N);
	cout << endl;
	cout << "=>" << endl;
	cout << endl;

	rotate(M,N);
	printMatrix(M,N);
}

int main(){
	test();
	return 0;
}