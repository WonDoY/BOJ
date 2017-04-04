#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 100001
using namespace std;
// global variable
int a[MAX];
bool visited[MAX];
bool save[MAX];
int size;
queue<int> q;
// end
void init();
void qinit();
void input();
void copy(int start);
bool cycle(int start);
int printResult();
void nonCycle(int start);
void printTeam(){
	for(int i = 1 ; i <= size ; i++){
		printf("%d : %d\n",i , save[i]);
	}
	
}
int main(){
	int tc;
	for( scanf("%d", &tc) ; tc-- ; ){
		scanf("%d", &size);		
		input();
		for(int i = 1 ; i <= size ; i++){
			if(!visited[i]){ // 방문하지 않았다면
				qinit();
				bool isCycle = cycle(i);
				
				if(isCycle){ // 사이클이 존재한다. 
					qinit(); // q capacity make empty.
					copy(i);
				}else if(!isCycle){
					qinit();
					nonCycle(i);
				}
			}
		}
		//printTeam();
		printf("%d\n", size - printResult());
		init();
	}
}
void nonCycle(int start){
	q.push(a[start]); // 수정
	while(!q.empty()){
		int next = q.front();
		q.pop();
		if(visited[next]){ // 방문했다면 풀어준다.
			visited[next] = false;
			q.push(a[next]);
		}else if(!visited[next]){ // 방문 표시가 되어있지 않다면
			return ; // 모든 방문 표시를 풀었다.
		}
	}
}
int printResult(){
	int ret = 0;
	for(int i = 1 ; i <= size ; i++){
		if(save[i]) ret++;
	}
	return ret;
}
void copy(int start){ 
	q.push(start);
	while(!q.empty()){ // 
		int next = q.front();
		q.pop();
		if(!save[next]){
			save[next] = true;
			q.push(a[next]);
		}
	}
}
bool cycle(int start){
	// 자기 자신으로 꽂히는 사이클이면 visited mark 하지 않음.
	if(start == a[start]){ // 자기 자신 사이클
		visited[start] = true;
		return true;
	}else if(start != a[start]){ // 자기 자신 사이클 아님
		q.push(start);
	}
	while(!q.empty()){
		int next = q.front();
		q.pop();
		
		if(a[next] == start){
			// 다음 이동할 위치와 시작한 위치가 같다.
			// 사이클이 존재한다.
			return true;
		}else if(!visited[next] && next != a[next] ){ 
			// 방문 x &&
			// 재귀사이클 x
			// 아직 사이클이 존재하는지 모른다.
			visited[next] = true;
			q.push(a[next]); // next element
		}else if(visited[next]){
			// 방문하였다. 
			// 사이클이 아니기 때문에
			// 이미 순회한 위치로 해당 순회는 필요없다.			  
			return false;
		}
	}
	return false;
}
void init(){
	for(int i = 1 ; i <= size ; i++){
		visited[i] = false;
		save[i] = false;
	}
}
void qinit(){
	while(!q.empty()) q.pop(); 
}
void input(){
	for(int i = 1 ; i <= size ; i++) scanf("%d" , &a[i]);
}

//1
//3
//2 3 2
// 85% 시간초과


//#include <bits/stdc++.h>
//#define REP(i,a,b) for(int i=a;i<=b;++i)
//#define FOR(i,n) for(int i=0;i<n;++i)
//#define pb push_back
//#define all(v) (v).begin(),(v).end()
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//using namespace std;
//typedef long long ll;
//typedef pair<ll,ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef vector<pair<int,int> > vii;
//typedef vector<vector<int> > vvi;
//typedef pair<int,int> pii;
//typedef pair<int,pair<int,int> > piii;
//const double EPSILON = 1e-9;
//const double PI = acos(0.0)*2;
//const int MOD = 1000000007;
//const int INF = 0x3c3c3c3c;
//const long long INFL = 0x3c3c3c3c3c3c3c3c;
//const int MAX_N = 100002;
//
//int indegree[MAX_N];
//int N,T;
//int sel[MAX_N];
//int main() {
//	for(inp1(T);T--;){
//		memset(indegree,0,sizeof(indegree));
//		queue<int> q;
//		inp1(N);
//		FOR(i,N) inp1(sel[i]),sel[i]--,indegree[sel[i]]++;
//		FOR(i,N) if(!indegree[i]) q.push(i);
//		int ans=0;
//		while(!q.empty()){
//			ans++;
//			int here = q.front();
//			q.pop();
//			indegree[sel[here]]--;
//			if(!indegree[sel[here]]) q.push(sel[here]);
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}
// add solve code 1

//#include <bits/stdc++.h>
//#define REP(i,a,b) for(int i=a;i<=b;++i)
//#define FOR(i,n) for(int i=0;i<n;++i)
//#define pb push_back
//#define all(v) (v).begin(),(v).end()
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//using namespace std;
//typedef long long ll;
//typedef pair<ll,ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef vector<pair<int,int> > vii;
//typedef vector<vector<int> > vvi;
//typedef pair<int,int> pii;
//typedef pair<int,pair<int,int> > piii;
//const double EPSILON = 1e-9;
//const double PI = acos(0.0)*2;
//const int MOD = 1000000007;
//const int INF = 0x3c3c3c3c;
//const long long INFL = 0x3c3c3c3c3c3c3c3c;
//const int MAX_N = 100002;
//
//int N,M;
//vi G[MAX_N];
//vi Gr[MAX_N];
//int visited[MAX_N];
//stack<int> s;
//int sccId[MAX_N];
//int idCnt;
//int T;
//int memberCnt[MAX_N];
//void dfs1(int here){
//	visited[here]=1;
//	for(int there : G[here]){
//		if(visited[there]) continue;
//		dfs1(there);
//	}
//	s.push(here);
//}
//void dfs2(int here){
//	sccId[here]=idCnt;
//	memberCnt[idCnt]++;
//	for(int there : Gr[here]){
//		if(sccId[there]!=-1) continue;
//		dfs2(there);
//	}
//}
//int main() {
//	for(inp1(T);T--;){
//		memset(sccId,-1,sizeof(sccId));
//		memset(visited,0,sizeof(visited));
//		memset(memberCnt,0,sizeof(memberCnt));
//		FOR(i,MAX_N) G[i].clear();
//		FOR(i,MAX_N) Gr[i].clear();
//		idCnt=0;
//		inp1(N);
//		FOR(i,N){
//			int a;
//			inp1(a);
//			a--;
//			G[i].pb(a);
//			Gr[a].pb(i);
//		}
//		FOR(i,N) {
//			if(visited[i]) continue;
//			dfs1(i);
//		}
//		while(!s.empty()){
//			int here = s.top();
//			s.pop();
//			if(sccId[here]!=-1) continue;
//			dfs2(here);
//			idCnt++;
//		}
//		int ans=0;
//		FOR(i,idCnt) if(memberCnt[i]==1) ans++;
//		FOR(i,N) if(G[i][0]==i) ans--;
//		printf("%d\n",ans);
//	}
//	return 0;
//}
// add solve code 2