#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<cstring>
#define MAX 10101
#define mp(a,b) make_pair(a,b)
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
priority_queue<pll, vector<pll>, greater<pll> > Q[MAX];
bool visited[MAX];

ll prim(ll start){
	memset(visited, 0, MAX);
	visited[start] = true;
	ll ret = 0;
	
	while(!Q[start].empty()){
		pll p = Q[start].top();
		Q[start].pop();
		ll cost = p.first;
		ll next = p.second;

		if(visited[next]) continue;
		visited[next] = true;
		ret += cost;
		while(!Q[next].empty()){
			Q[start].push(Q[next].top());
			Q[next].pop();
		}
	}
	return ret;
}

void qinit(int v){
	for(int i = 0 ; i <= v ; i++){
		while(!Q[i].empty()) Q[i].pop();
	}
}

int main(){
	int tc;
	int v, e; 
	ll v1, v2;
	for(scanf("%d", &tc) ; tc-- ; ){
		scanf("%d %d", &v ,&e);
		for(int i = 0 ; i < e ; i++){
			scanf("%lld %lld", &v1, &v2);
			Q[v1].push(mp(1, v2));
			Q[v2].push(mp(1, v1));
		}
		printf("%lld\n", prim(1));
		qinit(v);
	}
	return 0;
}
