#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<functional>
#include<algorithm>
#define MAX 101010
#define mp(a,b) make_pair(a,b)
#define pll pair<ll, ll>
#define ONE second.first
#define TWO second.second.first
#define THR second.second.second
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll, pair<ll, ll> > > ppp;

priority_queue<pll, vector<pll>, greater<pll> > Q[MAX];
bool visited[MAX];

ll ab(ll a){
	if(a < 0) return -a;
	return a;
}

ll min3(ll a, ll b, ll c){
	ll ret = a;
	if(ret > b) ret = b;
	if(ret > c) ret = c;
	return ret;
}

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
 

ppp input[MAX];
bool compx(const ppp& a, const ppp& b){
	if(a.ONE > b.ONE) return true;
	return false;
}
bool compy(const ppp& a, const ppp& b){
	if(a.TWO > b.TWO) return true;
	return false;
}
bool compz(const ppp& a, const ppp& b){
	if(a.THR > b.THR) return true;
	return false;
}

void make_uvw(int i){
	ll w ,x, y, z;
	ll v1, v2;
	v1 = input[i].first;
	v2 = input[i-1].first;
	x = ab(input[i].ONE - input[i-1].ONE);
	y = ab(input[i].TWO - input[i-1].TWO);
	z = ab(input[i].THR - input[i-1].THR);
	w = min3(x,y,z);
	Q[v1].push(mp(w, v2));
	Q[v2].push(mp(w, v1));
}

int main(){
	int v; 	
	scanf("%d", &v);
	for(ll v1 = 0 ; v1 < v ; v1++){
		input[v1].first = v1;
		scanf("%lld %lld %lld", &input[v1].second.first, &input[v1].second.second.first, &input[v1].second.second.second);
	}
	
	sort(input, input+v, compx);
	for(int i = 1 ; i < v ; i++) make_uvw(i);		

	sort(input, input+v, compy);
	for(int i = 1 ; i < v ; i++) make_uvw(i);		
	
	sort(input, input+v, compz);
	for(int i = 1 ; i < v ; i++) make_uvw(i);
		
	printf("%lld", prim(1));
	return 0;
}



//#include<iostream>
//#include<vector>
//#include<cstdio>
//#include<queue>
//#include<math.h>
//
//using namespace std;
//#define min(a,b) a<b?a:b
//int arr[100001][3];
//int par[100001];
//int ran[100001];
//priority_queue<pair<int,pair<int,int> > > q;
//int n;
//
//int find(int q){
//    if(par[q]==q)return q;
//    else return par[q]=find(par[q]);
//}
//void united(int p,int q){
//    if(ran[p]>ran[q]){
//        par[q]=p;
//    }
//    else{
//        par[p]=q;
//        if(ran[p]==ran[q])
//            ran[q]++;
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        par[i]=i;
//        ran[i]=0;
//        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
//    }
//    for(int i=0;i<n;i++){
//        for(int j=i+1;j<n;j++){
//            int cost=min(abs(arr[i][0]-arr[j][0]),min(abs(arr[i][1]-arr[j][1]),abs(arr[i][2]-arr[j][2])));
//            q.push(make_pair(-cost,make_pair(i,j)));
//        }
//    }
//    
//    
//    int edgenum=0;
//    int ans=0;
//    while(edgenum+1!=n){
//        int x=find(q.top().second.first);
//        int y=find(q.top().second.second);
//        int cost=-q.top().first;
//        q.pop();
//        if(x!=y){
//            edgenum++;
//            ans+=cost;
//            united(x,y);
//        }
//    }
//    printf("%d",ans);
//}

// sgc109
//#include <bits/stdc++.h>
//#define REP(i,a,b) for(int i=a;i<=b;++i)
//#define FOR(i,n) for(int i=0;i<n;++i)
//#define pb push_back
//#define all(v) (v).begin(),(v).end()
//#define sz(v) ((int)(v).size())
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//using namespace std;
//typedef long long ll;
//typedef pair<ll,ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int,int> pii;
//typedef vector<pii> vii;
//typedef vector<pll> vll;
//typedef vector<vector<int> > vvi;
//typedef pair<int,pair<int,int> > piii;
//typedef vector<piii> viii;
//const double EPSILON = 1e-9;
//const double PI = acos(0.0)*2;
//const int MOD = 1000000007;
//const int INF = 0x3c3c3c3c;
//const long long INFL = 0x3c3c3c3c3c3c3c3c;
//const int MAX_N = 102;
//
//int N,M,a,b,c;
//int p[100003],h[100003];
//viii edges;
//vii sorted[3];
//int cords[100003][3];
//int find(int here){
//	if(p[here]==here) return here;
//	return p[here]=find(p[here]);
//}
//void merge(int a, int b){
//	a=find(a),b=find(b);
//	if(h[a]<h[b]) swap(a,b);
//	p[b]=a;
//	if(h[a]==h[b]) h[a]++;
//}
//bool inRange(int x){
//	return 0<=x&&x<N;
//}
//int main() {
//	inp1(N);
//	REP(i,1,N) p[i]=i,h[i]=1;
//	REP(i,1,N){
//		FOR(j,3){
//			inp1(a);
//			cords[i][j]=a;
//			sorted[j].pb({a,i});
//		}
//	}
//	FOR(i,3) sort(all(sorted[i]));
//	REP(i,1,N){
//		FOR(j,3){
//			int idx = lower_bound(all(sorted[j]),pii(cords[i][j],i))-sorted[j].begin();
//			if(inRange(idx-1)) edges.pb({sorted[j][idx].first-sorted[j][idx-1].first,{sorted[j][idx].second,sorted[j][idx-1].second}});	
//			if(inRange(idx+11)) edges.pb({sorted[j][idx+1].first-sorted[j][idx].first,{sorted[j][idx].second,sorted[j][idx+1].second}});	
//		}
//	}
//	ll ans=0;
//	sort(all(edges));
//	for(auto e : edges){
//		int u = e.second.first, v = e.second.second;
//		int cost = e.first;
//		if(find(u)==find(v)) continue;
//		ans+=cost;
//		merge(u,v);
//	}
//	printf("%lld",ans);
//	return 0;
//}


// kth004
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<vector>
//#include<queue>
//#include<cmath>
//#include<algorithm>
//#define R 100001
//using namespace std;
//typedef pair<int,int> pi;
//int n;
//int p[R];
//vector<pi> x,y,z;
//
//struct Edge{ // 각 에지 비용과 연결된 두 정점. 
//	int cost,u,v;
//
//};
//
//struct cmp{ // 연산자 오버로딩 내림차순. 
//	bool operator()(Edge a,Edge b){
//		return a.cost>b.cost;
//	}
//};
//
//int find(int pos){ // 해당 정점의 루트를 탐색. 
//	if(pos==p[pos]) return pos;
//	else return p[pos]=find(p[pos]);
//}
//
//int merge(int u,int v){ // 별개의 컴포넌트인지 판단. 
//	int x,y;
//	x=find(u);
//	y=find(v);
//
//	if(x!=y){ // 별개일때 합병.(즉 루트를 동일시 하게된다.)
//		p[y]=x;
//		return 1;
//	}
//	return 0;
//}
//
//int main(){
//	int i,a,b,c;
//	scanf("%d",&n);
//
//	for(i=1;i<=n;i++){
//		scanf("%d%d%d",&a,&b,&c);
//		x.push_back(make_pair(a,i)); // 해당 좌표와 노드 번호 갱신.
//		y.push_back(make_pair(b,i));
//		z.push_back(make_pair(c,i));
//	}
//
//	for(i=1;i<=n;i++) p[i]=i; // 맨첨에 각 정점은 하나의 컴포넌트 자기 자신만 가진다.
//
//	/* 각 행렬 정렬.*/
//	sort(x.begin(),x.end()); 
//	sort(y.begin(),y.end()); 
//	sort(z.begin(),z.end());
//
//	priority_queue<Edge,vector<Edge>,cmp> pq;
//
//	for(i=0;i<n-1;i++){ // 인접 정점간의 비용과 두 정점을 min heap에 갱신. 
//		int xd,yd,zd;
//		Edge e;
//
//		xd=abs(x[i].first-x[i+1].first);
//		e.cost=xd;
//		e.u=x[i].second;
//		e.v=x[i+1].second;
//		pq.push(e);
//		yd=abs(y[i].first-y[i+1].first);
//		e.cost=yd;
//		e.u=y[i].second;
//		e.v=y[i+1].second;
//		pq.push(e);
//		zd=abs(z[i].first-z[i+1].first);
//		e.cost=zd;
//		e.u=z[i].second;
//		e.v=z[i+1].second;
//		pq.push(e);
//	}
//
//	int cnt,ans;
//	cnt=n-1;
//	ans=0;
//	Edge k;
//
//	while(cnt!=0){ // 간선개수만큼 반복. 
//		int u,v,cost;
//		k=pq.top();
//		u=k.u;
//		v=k.v;
//		cost=k.cost;
//		pq.pop();
//
//		if(merge(u,v)==1){ // 루트가 동일하지 않을때 즉 각각의 컴포넌트가 별개일때 연결하면서 그 비용 추가.
//			ans+=cost;
//			cnt--;
//		}
//	}
//
//	printf("%d\n",ans);
//	return 0;
//}