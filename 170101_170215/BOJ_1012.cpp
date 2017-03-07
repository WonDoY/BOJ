#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 100
#define mp(a,b) make_pair(a,b)
#define max(a,b) (a>b)?a:b
using namespace std;
bool map[MAX][MAX] ;
int visited[MAX][MAX];
int dir[4][2] = { {1,0},
				{-1,0},
				{0,1},
				{0,-1} };
queue<pair<int,int> > q;
int col, row, num;
void init(){
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			map[i][j] = false;
			visited[i][j] = 0;
		}
	}
	while(!q.empty()){
		q.pop();
	}
}
pair<int, int> p;
void bfs(int count){
	while(!q.empty()){
		p = q.front();
		q.pop();
		int r = p.first;
		int c = p.second;
		for(int i = 0 ; i < 4 ; i++){
			int dr = r + dir[i][0];
			int dc = c + dir[i][1];
			
			if(map[dr][dc] && visited[dr][dc] == 0 
				&& 0 <= dr && dr < row 
				&& 0 <= dc && dc < col){
				visited[dr][dc] = count;
				q.push(mp(dr,dc));
			}
		}
	}

}
int main(){
	int tc;

	for(scanf("%d", &tc) ; tc-- ;){
		init();
		
		int result = 0;
		scanf("%d %d %d", &col , &row, &num);
		for(int i = 0 ; i < num ; i++){
			int c, r; 
			scanf("%d %d", &c, &r);
			map[r][c] = true;
		}
		int cnt = 0;
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				if(map[r][c] && visited[r][c]==0){
					q.push(mp(r,c));
					visited[r][c] = ++cnt;
					bfs(cnt);
				}
			}
		}
		for(int r = 0 ; r < row ; r++){
			for(int c = 0 ; c < col ; c++){
				result = max(result,visited[r][c]);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}