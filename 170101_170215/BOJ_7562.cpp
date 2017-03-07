#include<cstdio>
#include<algorithm>
#include<queue>
#define MAX 300
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
using namespace std;
int I;
int ny, nx;
int ey, ex;
int dir[8][2] = { {-1,-2}, {-2,-1},
				  {1,-2}, {2,-1},
				  {-1,2}, {-2,1},
				  {1,2}, {2,1}};
bool visited[MAX][MAX];
queue<pair<pair<int,int>,int> > q;
int bfs(){
	visited[ny][nx] = true;
	q.push(mpp(ny,nx,0));
	pair<pair<int,int>, int> p;
	while(!q.empty()){
		p = q.front();
		q.pop();
		int y = p.first.first;
		int x = p.first.second;
		int c = p.second;
		//printf("[%d, %d] = %d\n", y, x, c);
		if(y == ey && x == ex){
			return c;
		}
		for(int i = 0 ; i < 8 ; i++){
			int tempy = y + dir[i][0];
			int tempx = x + dir[i][1];
			if(!visited[tempy][tempx] && 0 <= tempy && tempy < I && 0 <= tempx && tempx < I){				
				visited[tempy][tempx] = true;
				q.push(mpp(tempy,tempx,c+1));
			}
		}
	}
	return 0;
}
void init(){
	while(!q.empty()){
		q.pop();
	}
	for(int i = 0 ; i < MAX ; i++)
		for(int j = 0 ; j < MAX ; j++) visited[i][j] = false;
}
int main(){
	int tc;
	int result;
	for(scanf("%d",&tc);tc--;){
		init();
		scanf("%d",&I);
		scanf("%d %d", &ny, &nx);
		scanf("%d %d", &ey, &ex);
		printf("%d\n",bfs());
	}
	return 0;
}