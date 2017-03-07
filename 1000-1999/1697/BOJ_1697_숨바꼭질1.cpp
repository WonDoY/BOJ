#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;
const int MAX = 100001; // 
int sta, fin; // n,k ~[0, 1e+5]
int visited[MAX];

int main(){
	scanf("%d%d",&sta,&fin);
	memset(visited, -1, sizeof(visited));
	queue<int> q;
	q.push(sta);
	visited[sta] = 0;

	while(!q.empty()){
		int here = q.front(); q.pop();

		if(here == fin) break;

		if(here-1 >= 0)
			if(visited[here-1] == -1) visited[here-1] = visited[here]+1, q.push(here-1); 
		if(here+1 < MAX)
			if(visited[here+1] == -1) visited[here+1] = visited[here]+1, q.push(here+1);
		if(2*here < MAX)
			if(visited[2*here] == -1) visited[2*here] = visited[here]+1, q.push(2*here);
	}

	printf("%d", visited[fin]);

	return 0;
}