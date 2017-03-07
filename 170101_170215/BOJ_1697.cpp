#include<cstdio>
#include<queue>
#define MAX 300000
#define INF 100001
#define min(a,b) (a<b)?a:b
using namespace std;
int result = 0x7fffffff; // global variable 은 선언만 해도 0으로 초기화
bool visited[MAX] = {0,};
// system stack 터짐 
void dfs(int start, int end, int count){
	if(start >= INF) return ;
	if(start == end){
		result = min(result, count);
		return ;
	}
	if(end < start){
		if(!visited[start-1] && (start-1) > -1){
			visited[start-1] = true;
			dfs(start-1, end, count+1);
			visited[start-1] = false;
		}
		return ;
	}
	//printf("starting... %d\n", start);
	if(!visited[start-1] && (start-1) > -1){
		visited[start-1] = true;
		dfs(start-1, end, count+1);
		visited[start-1] = false;
	}
	if(!visited[2*start] && (2*start) < INF){
		visited[2*start] = true;
		dfs(2*start, end, count+1);
		visited[2*start] = false;
	}
	if(!visited[start+1] && (start+1) < INF){
		visited[start+1] = true;
		dfs(start+1, end, count+1);
		visited[start+1] = false;
	}
}
queue<pair<int,int> > q;
int bfs(int s, int end,int c){
	q.push(make_pair(s,c));
	pair<int, int> current;
	while(!q.empty()){
		current = q.front();
		q.pop();
		int start = current.first;
		int count = current.second;

		if(start == end){
			return count;
		}
		//if(end < current.first){
		//	q.push(make_pair(current.first-1, current.second+1));
		//}else{
		if(!visited[start+1] && start+1 < INF){
			visited[start+1] = true;
			q.push(make_pair(current.first+1, current.second+1));
		}
		if(!visited[2*start] && start*2 < INF){
			visited[start*2] = true;
			q.push(make_pair(start*2, current.second+1));
		}
		if(!visited[start-1] && start-1 > -1){
			visited[start-1] = true;
			q.push(make_pair(current.first-1, current.second+1));
		}
		//}
	}
	return 0;
}
int main(){
	int s, e;
	scanf("%d %d",&s, &e);
	visited[s] = true;
	if(e <= s) {
		printf("%d",s-e);
	}
	else{
		result = bfs(s,e,0);
		//dfs(s,e,0);
		printf("%d", result);
	}

	return 0;
}
// 7% 시간초과