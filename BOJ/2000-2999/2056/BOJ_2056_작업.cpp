#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 0x7FFFFFFF;

int main(){
	int n;
	int ans = 0;
	scanf("%d", &n);
	VVI adj = VVI(n+1, VI(0,0));
	VI cost = VI(n+1, 0);
	VI result = VI(n+1, 0);
	VI deg = VI(n+1, 0);

	queue<int> Q;
	for(int v = 1 ; v <= n ; v++){
		scanf("%d %d",&cost[v] ,&deg[v]);
		if(deg[v] == 0){
			Q.push(v);
			result[v] = cost[v];
		}
		for(int j = 0 ; j < deg[v] ; j++){
			int u;
			scanf("%d", &u);
			adj[u].push_back(v);
		}
	}
	
	while(!Q.empty()){
		int here = Q.front(); Q.pop();
		ans = (cost[here] > ans)? cost[here] : ans; // add code

		for(auto iter = adj[here].begin() ; iter != adj[here].end() ; iter++){
			int there = *iter;
			if(result[there] < cost[there] + result[here]){
				result[there] = cost[there] + result[here];
				ans = (result[there] > ans)? result[there] : ans;
			}
			deg[there]--;
			if(deg[there]==0){
				Q.push(there);
			}
		}
	}
	printf("%d",ans);
	return 0;
}

// 100% WA