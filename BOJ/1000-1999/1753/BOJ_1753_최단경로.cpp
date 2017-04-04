#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
#include<memory.h>
#define mp(a,b) make_pair(a,b)
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VP;

const int INF = 0x7FFFFFFF;
const int VMAX = 20001;

int main(){
	int numOfV, numOfE;
	scanf("%d%d", &numOfV, &numOfE);

	VP E[VMAX];
	// Vertex ; cost, vis, path
	VVI V = VVI(numOfV+1, VI(3, 0));
	for(int i = 1 ; i <= numOfV ; i++){
		V[i][0] = INF;
		V[i][2] = -1;
	}
	
	int start;
	scanf("%d", &start);
	V[start][0] = 0; // start Vertex Cost is 0

	for(int i = 0 ; i < numOfE ; i++){
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(mp(v,w));
	}

	priority_queue<PII, vector<PII>, greater<PII> > Q;
	Q.push(mp(0,start));

	while(!Q.empty()){
		PII p = Q.top(); Q.pop();
		int here = p.second;
		if(V[here][1] != 0) continue;
		V[here][1] = 1;

		for(auto iter = E[here].begin() ; iter != E[here].end() ; iter++){
			PII p = *iter;
			int there = p.first;
			int cost = p.second;

			if(V[there][0] > V[here][0] + cost){
				V[there][0] = V[here][0] + cost;
				V[there][2] = here;
				Q.push(mp(V[there][0], there));
			}
		}
	}

	for(int i = 1 ; i <= numOfV ; i++){
		if(V[i][0] == INF) printf("INF");
		else printf("%d",V[i][0]);
		puts("");
	}

	//for(int i = 1 ; i <= numOfV ; i++){
	//	for(int parent = i ; parent != -1 ; parent = V[parent][2]){
	//		printf("%d ",parent);
	//	}
	//	puts("");
	//} // path 

	return 0;
}