#include<cstdio>
#include<vector>
#define MAX 100
using namespace std;
typedef long long ll;
ll memo[MAX];
vector<ll> v;

ll dy(int x){
	ll &ret = memo[x];
	if(ret != -1) return ret;
	
	return ret;
}
// 고정수는 그대로 가져간다.
// 유동적으로 움직이는 것만
int main(){
	int n; scanf("%d", &n);
	int vip; scanf("%d", &vip);
	v = vector<ll>(vip, 0);
	for(int i = 0 ; i < vip ; ++i) scanf("%d", &v[i]);

	printf("%lld", dy(1));
	return 0;
}