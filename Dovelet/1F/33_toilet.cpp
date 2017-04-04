#include<cstdio>

int main(){
	int N, max, min;
	scanf("%d",&N);
	(N & 1) ? max = N/2+1 : max = N/2 ;
	(N % 3 > 0) ? min = N/3+1 : min = N/3;
	printf("%d %d",max, min);
	return 0;
}