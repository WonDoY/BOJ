#include<cstdio>
#define MAX 1010
#define INF 0x00FFFFFF
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int adjM[MAX][MAX] ;
int G[MAX][MAX] ;

int n,m,x;

void init(){
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			adjM[i][j] = G[i][j] = INF;			
		}
	}
}
int main(){
	init();
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = 1;
		G[v][u] = 1;
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
	int result = INF;
	int person = 0;
	for(int r = 1 ; r <= n ; r++){
		int sum = 0;
		for(int c = 1 ; c <= n ; c++){
			if(r!=c) sum+=G[r][c];
		}
		if(result > sum){
			result = sum;
			person = r;
		}
	}
	printf("%d\n", person);
	return 0;
}
