#include<cstdio>
#include<vector>
#include<queue>
#define MAX 101010
#define pb(a) push_back(a)
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int node_root[MAX];
queue<int> Q;
void bfs(){
	Q.push(1);
	while(!Q.empty()){
		int here = Q.front();
		Q.pop();

		if( visited[here] ) continue;
		visited[here] = true;

		for(int i = 0 ; i < graph[here].size() ; i++){
			if(!visited[graph[here][i]]){
				node_root[graph[here][i]] = here;
				Q.push(graph[here][i]);
			}
		}
	}
	
}

int main(){
	int n;
	scanf("%d", &n);
	int vertex1, vertex2;
	for(int i = 1 ; i < n ; i++){
		scanf("%d %d", &vertex1, &vertex2);
		graph[vertex1].pb(vertex2);
		graph[vertex2].pb(vertex1);
	}

	bfs();

	for(int i = 2 ; i <= n ; i++){
		printf("%d\n",node_root[i]);
	}
	return 0;
}