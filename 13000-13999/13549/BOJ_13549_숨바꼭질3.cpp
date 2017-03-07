#include<cstdio>
#include<memory.h>
#include<queue>
using namespace std;

const int MAX = 100001;
int sta, fin;
int vis[MAX];

int main(){
	scanf("%d%d",&sta,&fin);
	memset(vis, -1, sizeof(vis));
	queue<int> q;
	q.push(sta);
	vis[sta] = 0;
	if(sta != 0){
		for(int temp = sta<<1; temp < MAX ; temp = temp << 1){
			vis[temp] = 0, q.push(temp);
		}
	}

	while(!q.empty()){
		int here = q.front(); q.pop();
		
		if(here == fin) break;

		if(here > 0){
			for(int temp = here<<1 ; temp < MAX ; temp = temp << 1){
				if(vis[temp] != -1) break;
				else if(vis[temp]==-1) vis[temp] = vis[here], q.push(temp);
			}
		}

		if(here-1 >= 0)
			if(vis[here-1] == -1) vis[here-1] = vis[here]+1, q.push(here-1);
		if(here+1 < MAX)
			if(vis[here+1] == -1) vis[here+1] = vis[here]+1, q.push(here+1);

	}

	printf("%d",vis[fin]);
	return 0;
}