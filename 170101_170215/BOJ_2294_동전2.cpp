#include<cstdio>
#include<cstring>
// 계단이랑 비슷한거 같은데
int coin[100];
int dp[222222];
int n, k;
const int INF = 0x00FFFFFF;
int min2(int a, int b){
	return (a>b)?b:a;
}

int dy(int t){
	if(t >= k) return INF;
	int &ret = dp[t];
	if(ret != -1) return ret;
	ret = INF;
	for(int i = 0 ; i < n ; i++){
		if(dp[t+coin[i]] == -1 || t+coin[i] > 11111) continue;
		ret = min2(ret, dp[t+coin[i]]);
	}
	if(ret != INF) ret++;
	
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	dp[k] = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &coin[i]);
		if(k-coin[i] >= 0) dp[k - coin[i]] = 1;
	}
	
	for(int i = k ; i >= 0 ; i--){
		dy(i);
	}

	if(dp[0] == INF) printf("-1");
	else printf("%d", dp[0]);
	return 0;
}