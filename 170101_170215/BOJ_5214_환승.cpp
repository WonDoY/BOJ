#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct info{
	int node;
	int count;
	info(int ni, int ci):node(ni), count(ci){}
};

VVI G;
VI visited;
int station, hyper, hypercount;
int main(){
	scanf("%d %d %d", &station, &hyper, &hypercount);
	G = VVI(station+1+hypercount,VI(0,0));
	visited = VI(station+1+hypercount,0);
	for(int i = 1 ; i <= hypercount ; i++){
		for(int j = 0 ; j < hyper ; j++){
			int t; scanf("%d", &t);
			G[t].push_back(station+i);
			G[station+i].push_back(t);
		}
	}

	queue<info> q;
	q.push(info(1,1));
	visited[1] = true;
	bool impossible = true;
	while(!q.empty()){
		info here = q.front(); q.pop();
		if(here.node == station){
			printf("%d", here.count);
			impossible = false;
			return 0;
		}
		for(auto iter = G[here.node].begin() ; iter != G[here.node].end() ; iter++){
			int tnode = *iter;
			if(!visited[tnode]){
				visited[tnode] = true;
				if(station < tnode && tnode <= station+hypercount) q.push(info(tnode, here.count));
				else q.push(info(tnode, here.count+1));
			}
		}
	}

	if(impossible){
		printf("-1");
	}
	
	return 0;
}