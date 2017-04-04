#include<cstdio>
#include<vector>
#include<cstring>
#define MAX 1010
using namespace std;
int n, m, k;
vector<int> adj[MAX];

int aMatch[MAX], bMatch[MAX];
bool visited[MAX];

bool dfs( int start){
	if(visited[start]) return false;
	visited[start] = true;

	for(auto iter = adj[start].begin() ; iter != adj[start].end() ; iter++){
		int next = *iter;
		if(bMatch[next] == -1 || dfs(bMatch[next]) ){
			aMatch[start] = next;
			bMatch[next] = start;
			return true;
		}
	}
	return false;
}

int bi_partite_match(){
	memset(aMatch, -1, sizeof(aMatch));
	memset(bMatch, -1, sizeof(bMatch));

	int size = 0;
	const int marks = k;
	for(int i = 0 ; i <= marks ; i++){
		bool isAdd = false; // 벌점을 다 못쓰는 상황이 생길수도 있음.
		for(int start = 1 ; start <= n ; start++){
			memset(visited,false,sizeof(visited) );

			if(k > 0){
				if(dfs(start)){
					if(i > 0 && k > 0) k--;
					size++;
					isAdd = true;
				}
			}
		}
		if(!isAdd) break;
	}

	return size;
}
int main(){
	scanf("%d %d %d", &n, &m, &k) ;
	for(int emp = 1 ; emp <= n ; emp++){
		int count = 0 ; 
		for(scanf("%d", &count) ; count-- ; ){
			int work;
			scanf("%d", &work);
			adj[emp].push_back(work);
		}
	}
	int result = bi_partite_match();
	printf("%d", result );
	return 0;
}



//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <utility>
//#include <stack>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//#include <unordered_set>
//#include <set>
//#include <map>
//#define REP(i,a,b) for(int i = a; i < b;++i) 
//#define FOR(i,n) REP(i,0,n)
//#define mp make_pair
//#define pb push_back
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//
//using namespace std;
//
//typedef pair<long long, long long> pll;
//typedef vector<int> vi;
//typedef vector<vector<int> > vvi;
//
//const int INF = 0x3a3a3a3a;
//const long long INFL = 0x3a3a3a3a3a3a3a3a;
//const int MAX_N = 1000, MAX_M = 1000;
//const int MAX_V = 2+MAX_N+MAX_M;
//
//
//int cap[MAX_V+1][MAX_V+1],flow[MAX_V+1][MAX_V+1];
//vvi adj;
//int n,m,k;
//
//
//vi parent;
//int dfs(int here, int finish) {
//	if(here == finish) return -1;
//	int ret=0;
//	FOR(i,adj[here].size()) {
//		int there = adj[here][i];
//		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
//			parent[there] = here;
//			ret = dfs(there, finish);
//			if(ret==-1) return ret;
//		}
//	}
//	return ret;
//}
//int edmonds(int start, int finish) {
//	int ret = 0;
//	
//	while(true){
//		
//		parent = vi(MAX_V+1,-1);
//		parent[start] = start;
//		if(dfs(start, finish) != -1) break;
//
//		int minFlow = INF;
//		for(int p = finish; p != parent[p]; p = parent[p]) {
//			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
//		}
//		for(int p = finish; p != parent[p]; p = parent[p]) {
//			flow[parent[p]][p] += minFlow;
//			flow[p][parent[p]] -= minFlow;
//		}
//		ret += minFlow;
//	}
//	return ret;
//
//}
//int main() {
//	inp3(n,m,k);
//	adj = vvi(MAX_V+1,vi());
//	FOR(i,n){
//		int c;
//		inp1(c);
//		FOR(j,c){
//			int a;
//			inp1(a);
//			--a;
//			cap[2+i][2+MAX_N+a] = 1;
//			adj[2+i].pb(2+MAX_N+a);
//			adj[2+MAX_N+a].pb(2+i);
//		}
//		cap[0][2+i] = 1;
//		adj[0].pb(2+i);
//		adj[2+i].pb(0);
//
//		cap[MAX_V][2+i] = 1;
//		adj[MAX_V].pb(2+i);
//		adj[2+i].pb(MAX_V);
//	}
//	FOR(i,m) {
//		cap[2+MAX_N+i][1] = 1;
//		adj[2+MAX_N+i].pb(1);
//		adj[1].pb(2+MAX_N+i);
//	}
//	cap[0][MAX_V] = k;
//	adj[0].pb(MAX_V);
//	adj[MAX_V].pb(0);
//
//	int ans = edmonds(0,1);
//	printf("%d",ans);
//	return 0;
//}

// starlett
//#include <stdio.h>
//#include <queue>
//#include <string.h>
//#include <vector>
//#include <map>
//using namespace std;
//int N, M, K;
//vector<int> g[2003];
//int r[2003][2003], par[2003], minr[2003];
//int bfs() {
//	memset(par, -1, sizeof(par));
//	queue<int> q;
//	q.push(0);
//	par[0] = 0;
//	minr[0] = 1e9;
//	while (!q.empty()) {
//		int now = q.front(); q.pop();
//		for (auto i : g[now])
//			if (r[now][i] && par[i] == -1) {
//				q.push(i);
//				par[i] = now;
//				minr[i] = min(minr[now], r[now][i]);
//				if (i == N + M + 2) return minr[i];
//			}
//	}
//	return 0;
//}
//int main() {
//	scanf("%d %d %d", &N, &M, &K);
//	g[0].push_back(1); g[1].push_back(0);
//	r[0][1] = K;
//	for (int i = 2; i <= N + 1; i++) {
//		g[0].push_back(i); g[i].push_back(0);
//		g[1].push_back(i); g[i].push_back(1);
//		r[0][i] = 1;
//		r[1][i] = K;
//	}
//	for (int i = 2; i <= N + 1; i++) {
//		int n; scanf("%d", &n);
//		while (n--) {
//			int go; scanf("%d", &go);
//			g[i].push_back(N + 1 + go); g[N + 1 + go].push_back(i);
//			r[i][N + 1 + go] = 1;
//		}
//	}
//	for (int i = N + 2; i <= N + M + 1; i++) {
//		g[i].push_back(N + M + 2);
//		r[i][N + M + 2] = 1;
//	}
//	int sum = 0, ret;
//	while (ret = bfs()) {
//		sum += ret;
//		int now = N + M + 2;
//		while (now) {
//			r[par[now]][now] -= ret;
//			r[now][par[now]] += ret;
//			now = par[now];
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}