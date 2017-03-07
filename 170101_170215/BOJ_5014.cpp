// 5014 start link 
#include<cstdio>
#include<algorithm>
#include<queue>
#define MAX 1000001
#define INF 0x7FFFFFFF
#define min(a,b) (a<b)?a:b;
#define mp(a,b) make_pair(a,b)
using namespace std;
int F, G, S, U, D;
int result = INF;
char* failCommand = "use the stairs\0";
bool visited[MAX];
//void dfs(int start, int count){
//	if(start > F) return ;
//	if(start < 1) return ;
//	if(start == G){
//		result = min(result, count);
//	}
//
//	if(!visited[start+U]){
//		visited[start+U] = true;
//		dfs(start+U,count+1);
//		visited[start+U] = false;
//	}
//	if(!visited[start-D]){
//		visited[start-D] = true;
//		dfs(start-D,count+1);
//		visited[start-D] = false;
//	}
//}
queue<pair<int,int> > q;
int bfs(int start, int count){
	q.push(mp(start, count));
	visited[start] = true;
	pair<int, int> p;
	while(!q.empty()){
		p = q.front();
		q.pop();
		int floor = p.first;
		int c = p.second;
		if(floor == G){
			return c;
		}
		if(!visited[floor+U] && floor+U <= F){
			visited[floor+U] = true;
			q.push(mp(floor+U, c+1));
		}
		if(!visited[floor-D] && floor-D >= 0){
			visited[floor-D] = true;
			q.push(mp(floor-D, c+1));
		}
	}
	return -1;
}
int main(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	visited[S] = true;
	
	//dfs(S,0);
	result = bfs(S,0);
	if(result == -1){
		printf("%s",failCommand);
	}else{
		printf("%d", result);
	}
	
	return 0;
}