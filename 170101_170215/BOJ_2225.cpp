#include<cstdio>
#define For(i,n) for(int a=i ; a < n ; ++a)
#define MAX 201
// input 0~N , K �� ���� ���� N�� �Ǵ� ����� �� 
// N ~ [1,200] K ~ [1,200]
// output 1,000,000,000 (10��) ���� ���� ������ ��� long long 
// 0����!!! ���ϴ� ��!
// 1 ~ 1 / 1 0 , 0 1 / 0 0 1 , 0 1 0 , 1 0 0 / 
// 2 ~ 2 / 1 1 ,2 0, 0 2 / 0 0 2 , 0 2 0 , 2 0 0 , 1 1 0 , 1 0 1 , 0 1 1 / 1 1 1 1 
// 3 ~ 3 / 2 1 , 1 2 / 1 1 1 
// 4 ~ 4 / 3 1 , 2 2 , 1 3 / 2 1 1 , 1 2 1 , 1 1 2 / 1 1 1 1 
// 5 ~ 5 / 4 1 , 2 3 , 3 2 , 1 4 / 3 1 1 , 1 3 1 , 1 1 3 , 2 2 1 , 2 1 2 , 1 2 2 / 
// 5�� 3�� ���� �Ƿ��� 3a + 2b + 1c ~ 4d �� ������ ������ 2����, a+b+c = 3 �ΰ��� ã��.
// (a,b,c) ~ (1,0,2)
// (a,b,c) ~ (  2,1)
// (a,b,c) ~ (     ) �� 2���� ���. �׷��Ƿ� �Ʒ� ���̺� 
// a+b+c = 4 
// (a,b,c) ~ (0,1,3) ~ 4 

//     4   5           4                       1
// N~4 K1  K2          K3                     K4
// 200 by 200 Matrix
//  K
//N 0  1  2  3  4  5  6  7 ...
//  1  1  0  0  0  0  0  0     
//  2 (1  1) 0  0  0  0  0     
//  3 (1 [2) 1] 0  0  0  0     
//  4  1 (3)[3] 1  0  0  0 ...
// expect 5
// e5  1  4  6  4  1  0  0  ....
//  5  1 
//  6  1
// �� ǥ��� ���� �� �ִ� ���� 1 ���� N���� �϶� 

//N 0  1  2  3  4  5  6  7 ...
//  1  1  2  3  4  5  6  7     
//  2  1  3  6 10
//  3 (1 [2) 1] 0  0  0  0     
//  4  1 (3)[3] 1  0  0  0 ...
// expect 5
// e5  1  4  6  4  1  0  0  ....
//  5  1 
//  6  1
int N;
int K;
typedef long long ll;

ll table[MAX][MAX] = {0,};
void printTable(){
	for(int r = 0 ; r <= N ; r++){
		for(int c = 0 ; c <= N ; c++)
			printf("%lld ",table[r][c]);

		printf("\n");
	}

}
int main(){
	scanf("%d", &N);
	scanf("%d", &K);
	//table[0][0] = -1;
	//table[0][1] = 2;
	
	//For(1,MAX){		
	//	For(1,MAX){

	//	}
	//}
	for(int c = 1 ; c < MAX ; c++) table[1][c] = c;
	for(int r = 2 ; r < MAX ; r++){
		table[r][1] = table[r-1][0] + table[r-1][1];
		for(int c = 2 ; c < MAX ; c++){
			//table[r][c] = (table[r-1][c] + table[r-1][c-1])%1000000000;
			table[r][c] = (table[r][c-1] + table[r-1][c])%1000000000;
		}
	}
	ll sum = 0;
	/*for(int col = 0 ; col < MAX ; col++) sum=(sum+table[N][col])%1000000000;*/
	sum = table[N][K];
	//printTable();
	printf("%lld\n", sum);
	return 0;
}