#include<cstdio>
#define MAX 1010
#define INF 0x00FFFFFF
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int adjM[MAX][MAX] ;
int G[MAX][MAX] ;

int n,m,x;

void printAdj(){
	printf(" << Adj Matrix >>\n");
	for(int r = 1 ; r <= n ; r++){
		for(int c = 1; c <= n ; c++){
			printf("%d ", adjM[r][c]);
		}
		printf("\n");
	}
}

void printG(){
	for(int r = 1 ; r <= n ; r++){
		for(int c = 1; c <= n ; c++){
			printf("%d ", G[r][c]);
		}
		printf("\n");
	}
}

void init(){
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			if(i!=j) adjM[i][j] = G[i][j] = INF;
			else G[i][j] = 0;
		}
	}
}
int main(){
	init();
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adjM[u][v] = w;
		G[u][v] = min(w,G[u][v]);
	}
	//printAdj();

	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
					//printG();
				}
			}
		}
	}
	int result = 0;
	for(int i = 1 ; i <= n ; i++){
		if(G[i][i] != INF){
			result = max(result, G[i][i]);
		}
	}
	//printf("%d\n", result);
	printG();
	return 0;
}
