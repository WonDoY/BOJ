
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 10101
#define mp(a,b) make_pair(a,b)
using namespace std;

bool visited[MAX];
vector<pair<int, int> > tree[MAX];
vector<pair<int, int> > graph[MAX];
int maxCost = 0;
int maxLeaf = 0;
void dfs( int start, int cost ){
	
	if(maxCost < cost){
		maxCost = cost;
		maxLeaf = start;
	}
	for(int i = 0 ; i < tree[start].size() ; i++){
		int child = tree[start][i].first;
		int weight = tree[start][i].second;
		dfs(child, cost + weight);
	}
}

int resCost = 0;
queue<pair<int, int> > Q;
void bfs( int start ){
	pair<int, int> p;
	Q.push(mp(start, 0) );
	while(!Q.empty()){
		p = Q.front();
		Q.pop();

		int there = p.first;
		int cost = p.second;

		if( visited[there] ) continue;
		visited[there] = true;

		if(resCost < cost){
			resCost = cost;
		}
		
		for(int i = 0 ; i < graph[there].size() ; i++){
			int tmpThere = graph[there][i].first;
			int tmpCost = graph[there][i].second;
			Q.push(mp(tmpThere ,tmpCost + cost) );
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int root, child, weight;
	for(int i = 1 ; i < n ; i++){
		scanf("%d %d %d", &root, &child, &weight);
		tree[root].push_back(mp(child, weight) );
		graph[root].push_back(mp(child, weight) );
		graph[child].push_back(mp(root, weight) );
	}
	dfs(1, 0);
	//printf("maxCost : %d\nmaxLeaf : %d\n", maxCost, maxLeaf);
	bfs(maxLeaf);
	printf("%d\n", resCost);
	return 0;
}