#include<cstdio>
#include<vector>
using namespace std;

typedef long long lld;
typedef vector<lld> VI;

int main(){
	int n;
	scanf("%d",&n);
	VI test = VI(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &test[i]);
	}
	lld a,b;
	scanf("%lld%lld",&a,&b);

	lld ans = 0;
	for(int i = 0 ; i < n ; i++){
		ans++;
		test[i] -= a;
		if(test[i] > 0){ // 주감독관이 들어가도 모자름, 부감독관 들어가야함.
			if( (test[i]%b) > 0){ // 부감독관의 배치수가 +1 해야하는 경우
				ans += (test[i]/b) + 1;
			}else if( (test[i]%b) == 0){ // 부감독관 배치수가 *n 으로 딱 맞음
				ans += (test[i]/b); 
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
// 63% WA - lld?