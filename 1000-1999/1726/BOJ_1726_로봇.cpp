#include<cstdio>
#include<vector>
#include<queue>
#define MAX 111
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

VVI imap;
bool vis[5][MAX][MAX];
int dir[5][2] = { {0,0}, {0,1} , {0,-1}, {1,0} , {-1,0} };

struct info{
	int r, c, d, cnt;
	info(int ri, int ci, int di, int cnti): r(ri), c(ci), d(di), cnt(cnti){}
};

int main(){
	int row, col;
	scanf("%d %d", &row, &col);
	imap = VVI(row, VI(col, 0) );

	for(int r = 0 ; r < row ; r++) 
		for(int c = 0 ; c < col ; c++) scanf("%d", &imap[r][c]); // input map
 
	int sr, sc, sd;
	int fr, fc, fd;
	scanf("%d %d %d", &sr, &sc, &sd);
	scanf("%d %d %d", &fr, &fc, &fd);

	--sr,--sc,--fr,--fc;

	queue<info> q;
	q.push(info(sr, sc, sd, 0));
	vis[sd][sr][sc] = true;

	while(!q.empty()){ // BFS
		info here = q.front(); q.pop();
		
		if(here.r == fr && here.c == fc && here.d == fd){
			printf("%d",here.cnt);
			break;
		}

		int td = (here.d > 2)? 1 : 3;

		for(int i = 0 ; i < 2 ; i++){
			if(!vis[td+i][here.r][here.c]){
				vis[td+i][here.r][here.c] = true;
				q.push(info(here.r, here.c, td+i, here.cnt+1));
			}
		} 

		for(int i = 1 ; i <= 3 ; i++){
			int tr = here.r + dir[here.d][0] * i;
			int tc = here.c + dir[here.d][1] * i;
			if(tr < 0 || row <= tr || tc < 0 || col <= tc || imap[tr][tc] == 1 ) break;
			if(!vis[here.d][tr][tc]){
				vis[here.d][tr][tc] = true;
				q.push(info(tr, tc, here.d, here.cnt+1));
			}
		}
	}
	return 0;
}
