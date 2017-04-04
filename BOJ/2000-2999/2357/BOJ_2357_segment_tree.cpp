#include<cstdio>
#include<vector>
#include<algorithm>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long ll;
const ll INF = 98765432100;

int make_height(int cnt){
	int ret = 1;
	while(cnt > 0){
		ret++;
		cnt = cnt >> 1;
	}
	return ret;
}

ll min2(ll a, ll b){
	return (a > b)? b : a;
}
ll max2(ll a, ll b){
	return (a > b)? a : b;
}

pll init(vll& a, vpll& tree, int node, int start, int end){
	if(start == end){		
		return tree[node] = mp(a[start], a[start]);
	}

	pll pleft = init(a, tree, 2*node, start, (start+end)/2);
	pll pright = init(a, tree, 2*node+1, (start+end)/2 + 1, end);

	return tree[node] = mp( min2(pleft.first , pright.first) , max2(pleft.second  , pright.second) );
}

pll query(vpll& tree, int node, int start, int end, int left, int right){
	if( end < left || right < start ) return mp(INF, 0);

	if( left <= start && end <= right ) return tree[node];

	pll pleft = query(tree, node*2, start, (start+end)/2, left, right);
	pll pright = query(tree, node*2+1, (start+end)/2 + 1, end, left, right);
	return mp( min2(pleft.first, pright.first) , max2(pleft.second, pright.second) );
}
int main(){
	int N, M;
	scanf("%d %d", &N, &M);		
	vll v(N);
	vpll tree(1 << make_height(N));
	for(int i = 0 ; i < N ; i++){
		scanf("%lld", &v[i]);
	}

	init(v, tree, 1, 0, N-1);
	int x, y;
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d", &x, &y);
		pll result = query(tree, 1, 0, N-1, x-1, y-1);
		printf("%lld %lld\n", result.first, result.second);
	}
	return 0;
}