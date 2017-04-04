#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 100
#define mppp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))
#define piiii pair<int, pair<int, pair<int,int>>>
using namespace std;

int map[MAX][MAX][MAX]; // hei row col
bool visited[MAX][MAX][MAX];
int dir[6][3] = { {1,0,0},
{-1,0,0},
{0,1,0},
{0,-1,0},
{0,0,1},
{0,0,-1} };
int result = 0;
queue<piiii> q;
piiii p;
int col, row, hei;
void printBoard(){
	for(int h = 0 ; h < hei ; h++){
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				printf("%2d",map[h][r][c]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
void bfs(){
	while(!q.empty()){
		p = q.front();
		q.pop();
		int h = p.first;
		int r = p.second.first;
		int c = p.second.second.first;
		int cnt = p.second.second.second;
		result = max(result, cnt);
		for(int di = 0 ; di < 6 ; di++){
			int dh = h + dir[di][0];
			int dr = r + dir[di][1];
			int dc = c + dir[di][2];
			if(0 <= dh && dh < hei 
				&& 0 <= dr && dr < row 
				&& 0 <= dc && dc < col){
					if(!visited[dh][dr][dc] && map[dh][dr][dc] == 0){
						visited[dh][dr][dc] = true;
						map[dh][dr][dc] = 1;
						q.push(mppp(dh,dr,dc,cnt+1));
					}
			}
		}
	}
}
int main(){

	scanf("%d %d %d", &col, &row, &hei);

	for(int h = 0 ; h < hei ; h++){
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				scanf("%d", &map[h][r][c]);
				if(map[h][r][c] == 1){
					visited[h][r][c] = true;
					q.push(mppp(h,r,c,0));
				}
			}
		}
	}
	bfs();

	bool isRipen = true;
	bool loopoutc = false;
	bool loopoutr = false;
	for(int r = 0 ; r < row ; r++){
		for(int c = 0 ; c < col ; c++){
			for(int h = 0 ; h < hei ; h++){
				if(map[h][r][c] == 0){
					isRipen = false;
					loopoutc = true;
				}
			}
			if(loopoutc) loopoutr = true;
		}
		if(loopoutr) break;
	}
	if(!isRipen){
		printf("-1");
	}else{
		printf("%d",result);
	}
	return 0;
}
