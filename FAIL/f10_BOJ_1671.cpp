#include<cstdio>
#include<vector>
#include<utility>
#include<tuple>
#include<cstdio>
#include<algorithm>
#define MAX 2222
using namespace std;
typedef long long ll;
vector<tuple<ll, ll, ll> > info[MAX];
int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++) {
		ll a,b,c;
		scanf("%lld %lld %lld", &info[i][0], &info[i][1], &info[i][2]);
	}
	sort(info, info+n);


	return 0;
}