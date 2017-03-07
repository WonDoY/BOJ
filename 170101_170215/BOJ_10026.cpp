#include<cstdio>
#include<algorithm>
#include<queue>
#define mppp(a,b,c) make_pair(a,make_pair(b,c))
#define MAX 100
using namespace std;
char map[MAX][MAX];
int v1[MAX][MAX];
int v2[MAX][MAX];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N;
queue<pair<int, pair<int, int> > > q;
pair<int, pair<int, int> > p;
//void printv1(){
//	for(int r = 0 ; r < N ; r++){
//		for(int c = 0 ; c < N ; c++){
//			printf("%2d",v1[r][c]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//void printv2(){
//	for(int r = 0 ; r < N ; r++){
//		for(int c = 0 ; c < N ; c++){
//			printf("%2d",v2[r][c]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
void bfsv1(){
	while(!q.empty()){
		p = q.front();
		q.pop();
		int r = p.first;
		int c = p.second.first;
		int cnt = p.second.second;
		for(int i = 0 ; i < 4 ; i++){
			int dr = r + dir[i][0];
			int dc = c + dir[i][1];
			if(map[r][c] == map[dr][dc] && v1[dr][dc] < 1
				&& 0 <= dr && dr < N
				&& 0 <= dc && dc < N){
					v1[dr][dc] = cnt;
					q.push(mppp(dr,dc,cnt));
			}
		}
	}
}
void bfsv2(){
	while(!q.empty()){
		p = q.front();
		q.pop();
		int r = p.first;
		int c = p.second.first;
		int cnt = p.second.second;
		for(int i = 0 ; i < 4 ; i++){
			int dr = r + dir[i][0];
			int dc = c + dir[i][1];
			if(map[r][c] == 'R' || map[r][c] == 'G'){
				if(('R' == map[dr][dc]|| 'G' == map[dr][dc]) && v2[dr][dc] < 1
					&& 0 <= dr && dr < N
					&& 0 <= dc && dc < N){
						v2[dr][dc] = cnt;
						q.push(mppp(dr,dc,cnt));
				}
			}
			else{
				if(map[r][c] == map[dr][dc] && v2[dr][dc] < 1
					&& 0 <= dr && dr < N
					&& 0 <= dc && dc < N){
						v2[dr][dc] = cnt;
						q.push(mppp(dr,dc,cnt));
				}
			}
		}
	}
}
void init(){
	while(!q.empty()){
		q.pop();
	}
}

int main(){

	scanf("%d ", &N);
	for(int r = 0 ; r < N ; r++) scanf("%s",map[r]);
	int cnt = 1;
	for(int r = 0 ; r < N ; r++){
		for(int c = 0 ; c < N ; c++){
			if(v1[r][c] < 1){
				v1[r][c] = cnt;
				q.push(mppp(r,c,cnt++));
				bfsv1();
			}
		}
	}
	init();
	cnt = 1;
	for(int r = 0 ; r < N ; r++){
		for(int c = 0 ; c < N ; c++){
			if(v2[r][c] < 1){
				v2[r][c] = cnt;
				q.push(mppp(r,c,cnt++));
				bfsv2();
			}
		}
	}
	int r1 = 0;
	int r2 = 0;
	for(int r = 0; r < N ; r++){
		for(int c = 0 ; c < N ; c++){
			if(r1 < v1[r][c]) r1 = v1[r][c];
			if(r2 < v2[r][c]) r2 = v2[r][c];
		}
	}
	printf("%d %d", r1, r2);
	return 0;
}