#include<cstdio>
#include<queue>
#include<memory.h>
#include<vector>
using namespace std;

const int MAX = 100001;
int sta, fin;
int vis[MAX];
int parent[MAX];
int main(){
	scanf("%d%d", &sta, &fin);
	memset(vis, -1, sizeof(vis));
	memset(parent, -1, sizeof(parent));
	queue<int> q;
	q.push(sta);
	vis[sta] = 0;

	while(!q.empty()){
		int here = q.front(); q.pop();

		if(here == fin) break;

		if(here-1 >= 0)
			if(vis[here-1]==-1) vis[here-1] = vis[here]+1, parent[here-1] = here, q.push(here-1);
		if(here+1 < MAX)
			if(vis[here+1]==-1) vis[here+1] = vis[here]+1, parent[here+1] = here, q.push(here+1);
		if(2*here < MAX)
			if(vis[2*here]==-1) vis[2*here] = vis[here]+1, parent[2*here] = here, q.push(2*here);
	}

	printf("%d\n",vis[fin]);

	vector<int> v;
	for(int par = fin ; par != -1 ; par = parent[par]) v.push_back(par);
	for(auto iter = v.rbegin() ; iter != v.rend() ; iter++) printf("%d ",*iter);

	return 0;
}