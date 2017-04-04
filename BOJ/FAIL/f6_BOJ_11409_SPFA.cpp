#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 444
#define MAXV 888
using namespace std;

int flow[MAXV][MAXV];
int capacity[MAXV][MAXV];
int cost[MAXV][MAXV];

vector<int> adj[MAXV];
const int INF = -0x00FFFFFF;

int dist[MAXV];
bool visited[MAXV];
int parent[MAXV];

int shortest_path_flow(int source, int sink){

	for(int i = 0 ; i < MAXV ; i++) dist[i] = INF;
	memset(visited, false, sizeof(visited) );
	memset(parent, -1, sizeof(parent) );

	dist[source] = source;
	queue<int> Q;
	Q.push(source);

	while(!Q.empty() ){
		int here = Q.front(); Q.pop();
		visited[here] = false;

		for(auto iter = adj[here].begin() ; iter != adj[here].end() ; iter++){
			int there = *iter;

			if(flow[here][there] < 1) continue;

			int edgeCost = cost[here][there];
			//if(dist[there] > dist[here] + edgeCost){ // 최소
			if(dist[there] < dist[here] + edgeCost){ // 최대
				dist[there] = dist[here] + edgeCost;
				parent[there] = here;
				if(!visited[there]){
					visited[there] = true;
					Q.push(there);
				}
			}
		}
	}

	for(int p = sink ; p != source  ; p = parent[p]){
		if(parent[p] == -1) break;
		flow[parent[p]][p] -= 1;
		flow[p][parent[p]] += 1;
	}
	return dist[sink];
}

void addEdge(int start_vertex, int end_vertex, int edgeCost){
	if(flow[start_vertex][end_vertex] < 1){
			adj[start_vertex].push_back( end_vertex );
			adj[end_vertex].push_back( start_vertex );
	}
	flow[start_vertex][end_vertex] += 1;
	cost[start_vertex][end_vertex] = edgeCost; 
	cost[end_vertex][start_vertex] = -edgeCost; // 간선상쇄
}

void makeSource(int source, int sourceLastNode){
	for(int i = source+1 ; i < sourceLastNode ; i++){
		addEdge(source, i, 0);
	}
}

void makeSink(int sink, int sinkStartNode){
	for(int i = sinkStartNode ; i < sink ; i++){
		addEdge(i, sink, 0);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int source = 0;
	int sink = n+m+1;
	for(int emp = 1 ; emp <= n ; emp++){
		int count = 0;

		for(scanf("%d", &count) ; count-- ; ){
			int work, work_cost;
			scanf("%d %d",&work, &work_cost);
			addEdge(emp, n + work, work_cost);
		}
	}

	makeSource(source, n+1);
	makeSink(sink, n+1);

	int resultCount = 0;
	int resultFlow = 0;

	while(1){
		int ret = shortest_path_flow(0, n+m+1);
		if(ret == INF) break;
		resultFlow += ret;
		resultCount++;
	}

	printf("%d\n%d",resultCount, resultFlow);
	return 0;
}