#include<stdio.h>
#include<algorithm>
#define MAX 1001
//#define FOR(i,n) for(int i = 0, i < (n), ++i)
int N;
int P[MAX] = {0,};
int res[MAX] = {0,};
int tot[MAX] = {0,};
void input();
void solve();

int main(){
	input();
	solve();
	return 0;
}
void input(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&P[i]);
	}
	std::sort(P+1,P+N+1);
}
void solve(){
	for(int i = 1 ; i <= N ; i++){
		res[i] = P[i] + res[i-1];
		tot[i] = res[i] + tot[i-1];
		//printf("P[ %d ] = %d, res[ %d ] = %d , tot[ %d ] = %d\n",i,P[i],i,res[i],i,tot[i]);
	}
	printf("%d\n",tot[N]);
}