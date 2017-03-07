#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1001
using namespace std;
// LCS : Longest Common Subsequence 최장, 공통, 부분열
int LCS[MAX][MAX] = {0,};
char A[MAX]={0,};
char B[MAX]={0,};

void printTable(int an, int bn){
	printf("      ");
	for(int i = 0 ; i < an ; i++){
		printf("%3c",B[i]);
	}
	printf("\n");
	for(int r = 0 ; r <= bn ; r++){
		
		printf("%3c",(r>0)?A[r-1]:'-');
		
		for(int c = 0 ; c <= an ; c++){
			printf("%3d",LCS[r][c]);
		}
		printf("\n");
	}
}
void print_LCS(int an, int bn){
	for(int idx = 1 ; idx <= an ; idx++){
		if(LCS[idx][bn]>LCS[idx-1][bn]){
			printf("%c",A[idx-1]);
		}
	}
}
int solve_LCS(int an, int bn){
	int ret = 0;
	for(int a = 1 ; a <= an ; a++){
		for(int b = 1 ; b <= bn ; b++){

			//printf("<%d, %d>(%c)%d == <%d,%d>(%c)%d\n",a,b,A[a-1],LCS[a-1][b-1],a-1,b-1,B[b-1],LCS[a][b]);
			if(A[a-1] == B[b-1]){
				LCS[a][b] = LCS[a-1][b-1] + 1; // diag
			}else{
				LCS[a][b] = max(LCS[a-1][b], LCS[a][b-1]);
			}
			ret = max(LCS[a][b],ret);
		}
	}
	return ret;
}

int main(){
	scanf("%s", A);
	scanf("%s", B);
	
	printf("%d\n",solve_LCS(strlen(A),strlen(B)));
	//printTable(strlen(A),strlen(B));
	print_LCS(strlen(A),strlen(B));
	return 0;
}