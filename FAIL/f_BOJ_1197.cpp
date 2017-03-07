//// prim
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#define MAX 10101
#define mp(a,b) make_pair(a,b)
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
priority_queue<pll, vector<pll>, greater<pll> > Q[MAX];
bool visited[MAX];

ll prim(ll start){
	ll ret = 0;
	visited[start] = true;
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

int main(){
	int v, e; 
	ll v1, v2, w;
	scanf("%d %d", &v ,&e);
	for(int i = 0 ; i < e ; i++){
		scanf("%lld %lld %lld", &v1, &v2, &w);
		Q[v1].push(mp(w, v2));
		Q[v2].push(mp(w, v1));
	}
	printf("%lld", prim(2));
	return 0;
}

//// kruskal??

//#include<cstdio>
//#include<vector>
//#include<queue>
//#include<functional>
//#include<set>
//#include<cstring>
//#define MAX 10101
//#define pb(a) push_back(a)
//#define mp(a,b) make_pair(a,b)
//#define pllpllll pair<ll, pair<ll, ll> >
//
//using namespace std;
//typedef long long ll;
//
//priority_queue<pllpllll, vector<pllpllll>, greater<pllpllll> > pq;
//vector<ll> G[MAX];
//vector<int> connect[MAX];
//bool visited[MAX];
//bool cycle[MAX];
//const ll INF = 99999999;
//// abs(1,000,000) -> 10,000 * 000,000 = 10,000,000,000
//set<int, int> s[MAX];
//bool isConnect(ll u, ll v, ll ban_v){ // 연결이 되어 있지 않다면 
//	// start -> start
//	// start -> end
//	// end -> start 
//	// end -> end
//	// 모두가 연결되어 있음을 안다.
//	bool ret = false;
//	// 둘다 이미 어떤 간선과 연결을 한 상태이다.
//	for(auto iter = G[u].begin() ; iter != G[u].end() ; iter++){
//		ll next = *iter;
//		if(ret) return ret;
//		if((*iter) == v) return ret = true;
//		
//		if(!cycle[next]){
//			cycle[next] = true;
//			ret = isConnect(next, v, u);
//		}
//		
//	}
//
//	return ret; // 사이클이 아님.
//}
//ll mst(){
//	// 두 노드가 다 방문되어있다면 사이클이다. 
//	pllpllll pp;
//	ll ret = 0;
//	while(!pq.empty()){ 
//		pp = pq.top();
//		pq.pop();
//		ll cost = pp.first;
//		ll v1 = pp.second.first;
//		ll v2 = pp.second.second;
//		
//		if(visited[v1] && visited[v2]){ // 둘다 방문한 상태일 때 cycle 체크
//			memset(cycle, 0, MAX);
//			if(!isConnect(v1, v2, v2)){
//				ret += cost;
//				G[v1].pb(v2);
//				G[v2].pb(v1);
//			}else{
//				continue;
//			}
//		}else{
//			visited[v1] = true;
//			visited[v2] = true;
//			ret += cost;
//			G[v1].pb(v2);
//			G[v2].pb(v1);
//		}
//	}
//	return ret;
//}
//
//
//int main(){
//	int vertex, edge;
//	scanf("%d %d", &vertex, &edge);
//
//	ll u, v, w;
//	for(int i = 0 ; i < edge ; i++){
//		scanf("%lld %lld %lld", &u, &v, &w);
//		pq.push(mp(w , mp(u,v)));
//	}
//
//	printf("%lld",mst());
//	return 0;
//}
//
//// TLE 9%