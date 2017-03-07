#include<cstdio>
#include<vector>
#include<queue> 
#include<cstring>
#define MAX 55
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct info{
	int r,c,cnt;
	info(int ri, int ci, int cnti):r(ri), c(ci), cnt(cnti) {}
};
VVI imap;
int dir[4][2] = { {1,0} , {-1,0}, {0,1} , {0,-1} };
int row, col;

int max(int a, int b){ return (a>b)?a:b ; }

int bfs(int sr, int sc){
	int ret = 0;
	if(imap[sr][sc] != 1) return 0;
	
	bool vis[MAX][MAX];
	memset(vis, 0, sizeof(vis));
	
	queue<info> q;
	q.push(info(sr,sc,0));
	vis[sr][sc] = true;

	while(!q.empty()){
		info here = q.front(); q.pop();
		ret = max(ret , here.cnt);
		for(int i = 0 ; i < 4 ; i++){
			int tr = here.r + dir[i][0];
			int tc = here.c + dir[i][1];
			if(0 <= tr && tr < row && 0 <= tc && tc < col){
				if(!vis[tr][tc] && imap[tr][tc] == 1){
					vis[tr][tc] = true;
					q.push(info(tr,tc,here.cnt+1));
				}
			}
		}
	}

	return ret;
}

int main(){
	scanf("%d %d", &row, &col);
	imap = VVI(row, VI(col, 0));

	char str[60];
	for(int r = 0 ; r < row ; r++){
		memset(str, 0x00, sizeof(str) );
		scanf("%s", str);
		for(int c = 0 ; c < col ; c++){
			if(str[c]=='W') imap[r][c] = 0;
			else if(str[c]=='L') imap[r][c] = 1;
		}
	}

	int res = 0;
	for(int r = 0 ; r < row ; r++){
		for(int c = 0 ; c < col ; c++){
			res = max(res, bfs(r,c));
		}
	}

	printf("%d",res);
	return 0;
}