#include<cstdio>
#include<vector>
#define max(a,b) (a>b)? a:b
#define MAX 10101
using namespace std;

int dp[MAX][2];
int cost[MAX];
int parentVisited[MAX];
vector<int> tree[MAX];
// 10,000 * 10,000 = 000,000,001

int dynamic(int nodeSelect, bool select){
	
	int& ret = dp[nodeSelect][select];
	if(ret != -1) return ret;
	ret = 0;

	for(auto iter = tree[nodeSelect].begin() ; iter != tree[nodeSelect].end() ; iter++){
		if(parentVisited[nodeSelect] == *iter) continue;
		parentVisited[*iter] = nodeSelect;

		if(select){
			ret += dynamic(*iter, false);
		}else if(!select){
			ret += max(dynamic(*iter, false), dynamic(*iter, true) + cost[*iter] );
		}
	}
	
	return ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n; 
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&cost[i]);
	}
	
	int u, v;
	for(int i = 1 ; i < n ; i++){
		scanf("%d %d", &u, &v );
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int res = max(dynamic(1,false), dynamic(1,true)+cost[1]);
	printf("%d",res);
	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <memory.h>
//#include <algorithm>
//typedef long long ll;
////using ll = long long;
//using namespace std;
//
//int p[10003], c[10003];
//vector < vector <int> > lnk;
//ll dp[10003][2];
//
//ll dy(int v, int i){
//	ll &ret = dp[v][i];
//	if(ret != -1)return ret;
//	ret = 0;
//	for(auto e = lnk[v].begin() ; e != lnk[v].end() ; e++){
//		if(p[v] == *e)continue;
//		p[*e] = v;
//		if(i == 1){
//			ret += dy(*e,0);
//		}else{
//			ret += max(dy(*e,0), c[*e] + dy(*e,1));
//		}
//	}
//	return ret;
//}
//
//int main(){
//
//	int n;
//	scanf("%d", &n);
//
//	for(int i=1; i<=n; i++)scanf("%d", &c[i]);
//
//	lnk.resize(n+1);
//
//	for(int i=1; i<n; i++){
//		int a, b;
//		scanf("%d %d", &a, &b);
//		lnk[a].push_back(b);
//		lnk[b].push_back(a);
//	}
//
//	memset(dp, 0xff, sizeof(dp));
//
//	printf("%lld\n", max(dy(1,0), c[1] + dy(1,1)));
//
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<vector>
//#define R 10001
//
//using namespace std;
//
//int p[R]; // 각 정점의 인원 수.
//int n; // 정점 개수.
//vector<int> adj[R]; // 인접 정점.
//int dp[R][2];  // 총 마을이 10000개이고 우수마을: 1 일때와 우수마을이 아닐떄: 0
//
//int f(int pos,int state,int parent){ // dp 풀이.
//	int j,v,v2;
//	v=0;
//	v2=0;
//
//	if(dp[pos][state]!=-1) return dp[pos][state];
//	
//	if(state==1) dp[pos][state]=p[pos]; // 해당 정점의 마을 주민 수.
//	else dp[pos][state]=0;
//
//	for(j=0;j<adj[pos].size();j++){
//		int next;
//		next=adj[pos][j];
//		if(next==parent) continue;
//		if(state==0){ // 부모노드가 우수마을이 아닐때는 아랫마을이 우수마을일때도 있고 아닐때도있음.
//			v=f(next,!state,pos); 
//			v2=f(next,state,pos);
//			dp[pos][state]+=max(v,v2); // 최댓 값을 지정. 
//		}
//		else dp[pos][state]+=f(next,!state,pos); // 부모노드가 우수마을이면 자식노드는 우수마을이 아님. 
//	}
//
//	return dp[pos][state];
//}
//
//int main(){
//	int i,a,b,v,v2,ans;
//	ans=0;
//	v=0;
//	v2=0;
//	scanf("%d",&n);
//
//	for(i=1;i<=n;i++){
//		scanf("%d",&p[i]);
//	}
//
//	for(i=0;i<n-1;i++){ // 인접행렬 갱신. 
//		scanf("%d%d",&a,&b);
//		adj[a].push_back(b);
//		adj[b].push_back(a);
//	}
//
//	memset(dp,-1,sizeof(dp)); // dp 초기화.
//
//	v=f(1,1,0); // 루트가 우수마을일때.
//	v2=f(1,0,0); // 루트가 우수마을이 아닐떄.
//
//	ans=max(v,v2); // 그중 최댓값. 
//
//	printf("%d\n",ans);
//
//	return 0;
//}