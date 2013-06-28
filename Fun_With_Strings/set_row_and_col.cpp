// If an element in an MxN matrix is zero, 
// its entire row and column are set to zero.

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

void setRowAndCol(int** A, int M, int N){
	assert(A != NULL && M >=0 && N >= 0);
	int i,j;
	bool rows[N];
	bool cols[N];
	memset(rows,false,sizeof(rows));
	memset(cols,false,sizeof(cols));
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(A[i][j] == 0){
				rows[i] = true;
				cols[j] = true;
			}
		}
	}
	for(i=0;i<M;i++){
		if(rows[i]){
			for(j=0;j<N;j++){
				A[i][j] = 0;
			}
		}
	}
	for(i=0;i<N;i++){
		if(cols[i]){
			for(j=0;j<M;j++){
				A[j][i] = 0;
			}
		}
	}
}

void test(){
	// Normal case
	int i,j;
	int** A = new int*[3];
	for(i=0;i<3;i++){
		A[i] = new int[3];
	}
	A[0][0] = 1;
	A[0][1] = 0;
	A[0][2] = 1;
	A[1][0] = 0;
	A[1][1] = 3;
	A[1][2] = 2;
	A[2][0] = 2;
	A[2][1] = 2;
	A[2][2] = 0;
	
	setRowAndCol(A, 3, 3);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			assert(A[i][j] == 0);
		}
	}
	// - Deallocate A
	for(i=0;i<3;i++){
		delete A[i];
	}
	cout << "Normal case OK" << endl;
	// - Extreme case
	int N = 10000;
	int M = 10000;
	A = new int*[N];
	for(i=0;i<N;i++){
		A[i] = new int[M];
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			A[i][j] = 1;
		}
	}
	setRowAndCol(A, M, N);
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			assert(A[i][j] != 0);
		}
	}
	cout << "Extreme case OK" << endl;
	// - Deallocate A
	for(i=0;i<M;i++){
		delete A[i];
	}
	// Strange input
	A = new int*[3];
	for(i=0;i<3;i++){
		A[i] = new int[3];
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			A[i][j] = 0;
		}
	}
	setRowAndCol(A, 3, 3);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			assert(A[i][j] == 0);
		}
	}
	for(i=0;i<3;i++){
		delete A[i];
	}
	cout << "Strange case OK" << endl;
}

int main(){
	test();
	return 0;
}