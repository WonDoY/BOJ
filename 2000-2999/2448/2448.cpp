#include<cstdio>

void solve2448(int s, int n){
	if(s == n) return;
	for(int i = 1 ; i < 2*n+1 ; i++){
		if(i==2*n){
			printf(" ");
		}
		else if( (i%(n-s)) == 0  ){
			printf("*");	
			//printf("*%d<%d,%d>",i,n,s);
		}
		else{
			printf(" ");
			//printf("%d<%d,%d>",i,n,s);
		}
	}
	printf("\n");
	
	solve2448(s+1, n);
	//solve2448(s,n-1);
	printf(" ");
}

int main(){
	int N;

	scanf("%d",&N);
	solve2448(0,N);

	return 0;
}
