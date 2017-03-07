#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct info{
	int nxt;
	int w;
	info(int in, int iw):nxt(in), w(iw){}
};

typedef vector<info> VIN;
typedef vector<VIN> VVIN;

int res[1111];
VVIN adj;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	adj = VVIN(n, VIN(0, 0));

	for(int i = 0 ; i < n ; i++){
		int u,v,w;
		scanf("%d%d%d", &u,&v,&w);
		adj[u].push_back(info(v,w));
	}

	int sta, fin;
	scanf("%d %d",&sta, &fin);

	

	printf("%d",res[fin]);
	return 0;
}