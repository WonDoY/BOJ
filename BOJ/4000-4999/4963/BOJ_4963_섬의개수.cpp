#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct info{
	int r;
	int c;
	info(int ri, int ci):r(ri),c(ci){}
};

VVI imap;
VVI visited;

int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
int row, col;

void bfs(int r, int c){
	queue<info> q;
	q.push(info(r,c));
	
	while(!q.empty()){
		info here = q.front(); q.pop();
		
		for(int i = 0 ; i < 8 ; i++){
			int tr = here.r + dr[i];
			int tc = here.c + dc[i];

			if(0 <= tr && tr < row && 0 <= tc && tc < col){
				if(!visited[tr][tc] && imap[tr][tc] == 1){
					visited[tr][tc] = true;
					q.push(info(tr,tc));
				}
			}
		}
	}
}

int main(){
	
	while(scanf("%d %d", &col, &row)){
		if(row == 0 && col == 0) return 0;

		imap = VVI(row, VI(col, 0));
		visited = VVI(row, VI(col, 0));
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				scanf("%d",&imap[r][c]);
			}
		}

		int result = 0;
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				if(!visited[r][c] && imap[r][c]==1){
					result++;
					bfs(r,c);
				}
			}
		}

		printf("%d\n", result);
	}
	
	

	return 0;
}