#include<cstdio>
#include<vector>
#define MAX 1010
using namespace std;
int n, m;
bool adj[MAX][MAX];
vector<int> aMatch, bMatch;
vector<bool> visited[2];

bool dfs(int num, int start){
	if(visited[num][start]) return false;
	visited[num][start] = true;

	for(int next = 1 ; next <= m ; next++){
		if(adj[start][next]){
			if(bMatch[next] == -1 || dfs(num, bMatch[next]) ){
				aMatch[start] = next;
				bMatch[next] = start;
				return true;
			}
		}
	}
	return false;
}

int bi_partite_match(){
	aMatch = vector<int>(n+1, -1);
	bMatch = vector<int>(m+1, -1);

	int size = 0;
	for(int start = 1 ; start <= n ; start++){
		visited[0] = vector<bool>(n+1, false);
		visited[1] = vector<bool>(n+1, false);
		if(dfs(0,start)) size++;
		if(dfs(1,start)) size++;
	}
	return size;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int emp = 1 ; emp <= n ; emp++){
		int count = 0 ; 
		for(scanf("%d", &count) ; count-- ; ){
			int work;
			scanf("%d", &work);
			adj[emp][work] = true;
		}
	}
	printf("%d", bi_partite_match());
	return 0;
}