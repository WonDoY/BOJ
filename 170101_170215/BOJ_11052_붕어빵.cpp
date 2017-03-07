#include<cstdio>
#include<cstring>
// 4
// 1 5 6 7
// f(total, sold#)
// if(total < sold#) nothing
// 1 5 6 7 f(4,1) f(4,2) f(4,3) f(4,4)
// 0 0 0 0 f(3,1) f(3,2) f(3,3) /f(3,4)
// 0 0 0 0 f(2,1) f(2,2) /f(2,3) /f(2,4)
// 0 0 0 0 f(1,1) /f(1,2) /f(1,3) /f(1,4)
int max2(int a, int b){
	return (a>b)?a:b;
}

int sold[1001];
int dp[1001][1001];

int dy(int total, int sell){
	if(total < sell || total <= 0) return 0;
	int &ret = dp[total][sell];
	if(ret != -1) return ret;
	ret = sold[sell];
	int temp = 0;
	for(int i = 1 ; i <= total-sell ; i++){
		temp = max2(temp, dy(total-sell, i));
	}
	ret += temp;
	return ret ;
}

int main(){
	int n; scanf("%d" , &n);
	int result = 0 ;
	for(int i = 1 ; i <= n ; i++) scanf("%d", &sold[i]);
	memset(dp, -1, sizeof(dp));
	for(int to = 1 ; to <= n ; to++){
		for(int se = 1 ; se <= n ; se++){
			result = max2(result, dy(to, se));
		}
	}
	printf("%d",result);
	return 0;
}