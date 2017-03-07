#include<cstdio>
#include<algorithm>
#include<queue>
// 20,000 * 20,000 = 400,000,000
#define VMAX 40000
#define EMAX 60000
#define inpdec3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define INF 0x7FFFFFFF
#define mp(Ve, Vw) make_pair(Ve, Vw)
#define pii pair<int, int>
using namespace std;
pair<bool, int> V[VMAX]; // Vertex: visited, weight
vector<pair<int, int> > Vdata[VMAX]; // weight , finish
int edge_count;
int vertex_count;
int start_edge;
//queue<pair<int, int> > q;
priority_queue<pii, vector<pii>, greater<pii> > pq; // weight , finish
void init(){
	for(int i = 1 ; i <= vertex_count ; i++){
		V[i].second = INF;
	}
	V[start_edge].second = 0;
}
int main(){
	scanf("%d %d", &vertex_count ,&edge_count);
	scanf("%d", &start_edge);
	init();
	int start, finish, weight;
	for(int in = 0 ; in < edge_count ; in++){
		inpdec3(start, finish, weight);
		Vdata[start].push_back(mp(weight, finish));
	} // input Data
	int temp_start = start_edge;

	V[start_edge].second = 0;
	pq.push(mp(0, start_edge) );
	pii p;
	while(!pq.empty()){
		p = pq.top();
		pq.pop();
		int temp_start = p.second;
		if(!V[temp_start].first){
			V[temp_start].first = true;
			
			for(auto iter = Vdata[temp_start].begin() ; iter != Vdata[temp_start].end() ; iter++){
				pii pairV = *iter;
				int there = pairV.second;
				int cost = pairV.first;
				if(V[there].second > V[temp_start].second + cost){
					V[there].second = V[temp_start].second + cost;
					pq.push(mp(V[there].second, there));
				}
			}
		}
	}

	for(int i = 1 ; i <= vertex_count ; i++){
		if(V[i].second == INF) printf("INF\n");
		else printf("%d\n",V[i].second);
	}

	return 0;
}
// 9 % TLE
// 9 % TLE
// 9 % RTE


////.......
//#include<cstdio>
//#include<queue>
//#include<algorithm>
//#include<vector>
//#define VMAX 20001
//#define pii pair<int, int>
//#define mp2(a,b) make_pair(a,b)
//using namespace std;
//pii 
//priority_queue<pii, vector<pii> , greater<pii> > pq;
//vector<pii> vertex_adj_list[VMAX];
//int inv, ine, ins;
//int main(){
//	int start, finish, weight;
//	scanf("%d %d", &inv, &ine);
//	scanf("%d", &ins);
//	for(int i = 0 ; i < ine ; i++){
//		scanf("%d %d %d", &start, &finish, &weight);
//		vertex_adj_list[start].push_back(mp2(finish, weight));
//	}
//	// weight ¼ø Á¤·Ä 
//	pq.push(mp2(0, ins));
//
//
//	return 0;
//}