#include<cstdio>
#define SIZE 2
int n = 0;
int A[SIZE][SIZE] = {{1,1},
					{1,0}};
int B[SIZE][SIZE] = {{1,1},
					{1,0}};
int I[SIZE][SIZE] = {{1,1},
					{1,0}};
int R[SIZE][SIZE] = {{1,1},
					{1,0}};
void fibonacci(int input);
void initMatrix(int M[][SIZE]);
int main(){
	scanf("%d", &n);
	fibonacci(n);
	printf("%d\n",A[0][1]);
	return 0;
}
void initMatrix(int M[][SIZE]){
	for(int r = 0 ; r < SIZE ; r++) for(int c = 0 ; c <SIZE ; c++) M[r][c] = I[r][c];
}
void fibonacci(int input){
	int tmp = 0;
	for(int square = 1 ; square < input ; square*=2){
		// a b b c 
		tmp = A[0][0];
		A[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
		A[0][1] = tmp*B[0][1] + A[0][1]*B[1][1];
		tmp = A[1][0];
		A[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
		A[1][1] = tmp*B[0][1] + A[1][1]*B[1][1];

		for(int r = 0 ; r < SIZE ; r++)
			for(int c = 0 ; c < SIZE ; c++) B[r][c] = A[r][c];
	}
}
// A[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
// A[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
// A[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
// A[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];