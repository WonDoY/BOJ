#include<cstdio>
#include<vector>
#include<memory.h>
#include<utility>
#define mp(a,b) make_pair(a,b)
using namespace std;

typedef long long lld;
const lld INF = 0x000000FFFFFFFFFF;

struct info{
	int next;
	lld weight;
	info(int ni, lld wi):next(ni), weight(wi){}
};

typedef vector<info> VIN;
typedef vector<int> VI;
typedef vector<lld> VL;
typedef vector<bool> VB;

VL V;
VIN t[11111];
VB vis;
lld ans;
lld dfs(int here, lld cost){
	lld ret = cost;
	for(auto iter = t[here].begin() ; iter != t[here].end() ; iter++){
		info there = *iter;
		if(!vis[there.next]){
			vis[there.next] = true;
			V[there.next] = V[here] + there.weight; // Vertex cost
			ret += dfs(there.next, V[there.next]); 
			if(ans < ret) return INF;
		}
	}
	return ret;
}
lld min2(lld a, lld b){
	return (a>b)?b:a;
}
int main(){
	for(;;){
		int n;
		scanf("%d", &n);
		if(n==0) break;

		for(int i = 0 ; i < n-1 ; i++){
			int v1,v2;
			lld w;
			scanf("%d%d%lld", &v1, &v2, &w);
			t[v1].push_back(info(v2,w));
			t[v2].push_back(info(v1,w));
		}
		
		ans = INF;
		for(int i = 0 ; i < n ; i++){
			vis = VB(n,false);
			V = VL(n, 0);
			vis[i] = true;
			ans = min2(ans,dfs(i, 0));
		}

		printf("%d\n",ans);
		for(int i = 0 ; i < n-1 ; i++){
			t[i].clear();
		}
	}
	return 0;
}
// 50% TLE