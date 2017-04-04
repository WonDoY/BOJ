#include<cstdio>
#define MAX 1010101
// 1,000,000 * 10,000 = 10, 000, 000 ,000  
typedef long long lld;
lld day[MAX];
int main(){
	int tc;
	for(scanf("%d", &tc); tc-- ;){
		int n; scanf("%d", &n);
		for(int i = 0 ; i < n ; i++) scanf("%lld", &day[i]);
		// n-1부터 시작
		lld maxDay = 0;
		lld income = 0;
		for(int i = n-1; i >= 0 ; i--){
			if(maxDay < day[i]) maxDay = day[i];
			if(maxDay > day[i]) income += (maxDay-day[i]);
		}
		printf("%lld\n",income);
	}
	return 0;
}