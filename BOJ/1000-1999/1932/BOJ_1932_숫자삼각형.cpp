#include<cstdio>
const int MAX = 1111;
int dp[MAX][MAX];
// 0 =   0
// 1 =  0 1
// 2 = 0 1 2 
// 3 =0 1 2 3
// f(r,c) = max(dp(r,c)+f(r-1,c-1) , dp(r,c)+f(r-1,c)); 
int max2(int a, int b){
	return (a>b)?a:b;
}
int main(){
	int n; scanf("%d", &n);
	int result = 0;
	for(int lev = 0 ; lev < n ; lev++){
		for(int c = 0 ; c <= lev ; c++){
			scanf("%d", &dp[lev][c]);
			if(lev!=0 && c != 0){
				dp[lev][c] += max2(dp[lev-1][c-1] , dp[lev-1][c]);
			}else if(lev!= 0 && c == 0){
				dp[lev][c] += dp[lev-1][c];
			}
			if(result < dp[lev][c]) result = dp[lev][c];
		}
	}
	printf("%d", result);
	return 0;
}