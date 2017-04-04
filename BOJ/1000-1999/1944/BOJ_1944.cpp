// n*n
// S 1
// K는 
// n~[1,50] t~[1,250]
#include<cstdio>
#include<queue>
#include<tuple>
#include<map>
#include<cstring>
#include<functional>
#define INF 0x0000FFFF
#define MAX 60

using namespace std;
char board[MAX][MAX];
int visited[MAX][MAX];
bool isVisit[MAX][MAX];
int n, kn;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

queue<tuple<int, int, int> > q;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q[300];
map<pair<int, int>, int> m;
vector<pair<int, int> > v;
// 모든 노드끼리의 서로의 도달할 수 있는 노드의 비용을 구하면 된다. 


/*
	printVisit(int, int) 진행하는거 보려고 만든함수
	@void
*/
void printVisit(int row, int col) {
	//system("cls");
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if(visited[r][c] == INF) printf(" %c",'X');
			else printf("%2d", visited[r][c]);
		}
		printf("\n");
	}
	printf("\n");
} 

/*
	initVisited() int Visited[] 를 INF 로 초기화하는 함수 (= 65500) 로 초기화
	@void
*/
void initVisited(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			visited[i][j] = INF;
		}
	}
}

/*
	int Visited[] 를 INF 로 초기화하는 함수 (= 65500) 로 초기화
	@void
*/
void initIsVisit(int row, int col){
	//for(int i = 0 ; i < n ; i++){
		//for(int j = 0 ; j < n ; j++){
		//	if(row <= i && col <= j)isVisit[i][j] = false;
		//	else isVisit[i][j] = true;
		//}
		memset(isVisit, false, sizeof(isVisit) );
	//}
}

/*
	boundCheck(row, col, cnt) BFS에서 진행할때 해당 위치가 갈수 있는 위치인지 확인한다.
	@bool
*/
bool boundCheck(int row, int col) {
	if (0 <= row && row < n
		&& 0 <= col && col < n
		&& board[row][col] != '1'
		) {
		return true;
	}
	return false;
}


void bfs(int count, int srow, int scol) {
	initIsVisit(srow, scol);
	q.push(make_tuple(count, srow, scol));

	visited[srow][scol] = -1;
	isVisit[srow][scol] = true;
	pair<int, int> p2(srow, scol);
	while (!q.empty()) {
		tuple<int, int, int> tp = q.front();
		q.pop();

		int currentcount = get<0>(tp);
		int currentrow = get<1>(tp);
		int currentcol = get<2>(tp);
		//printVisit(n,n);
		for (int i = 0; i < 4; i++) {
			int checkRow = currentrow + dir[i][0];
			int checkCol = currentcol + dir[i][1];

			if (boundCheck(checkRow, checkCol) && board[checkRow][checkCol] != -1) {

				if(isVisit[checkRow][checkCol]) continue; // 이미 방문했다면 가지 않는다.
				isVisit[checkRow][checkCol] = true;		  // 방문하지 않았다면 방문표시를 한다.

				int c = visited[checkRow][checkCol] = currentcount + 1;
				q.push(make_tuple(c, checkRow, checkCol));
				pair<int, int> p1(checkRow, checkCol);
				
				if (board[checkRow][checkCol] == 'S' || board[checkRow][checkCol] == 'K') {
					Q[m[p1]].push(make_pair(c, m[p2]));
					Q[m[p2]].push(make_pair(c, m[p1]));
				}
			}
		}
	}
	//printVisit(n,n);
}

bool visit[300];
int prim(int start) {

	int ret = 0;
	visit[start] = true;
	while (!Q[start].empty()) {
		pair<int, int> p = Q[start].top();
		Q[start].pop();
		int cost = p.first;
		int next = p.second;

		if (visit[next]) continue;
		visit[next] = true;
		ret += cost;
		//printf("[%d] cost + %d\n",next,cost);
		while (!Q[next].empty()) {
			if(!visit[Q[next].top().second]){
				Q[start].push(Q[next].top());				
			}
			Q[next].pop();
		}
	}
	return ret;
}
// 그런데 S와 K는 동치로 봐도 되겠다. 어차피 모든 노드를 다연결할거니까

int main() {

	int keyCount = 1;
	scanf("%d %d ", &n, &kn);
	for (int r = 0; r < n; r++) {
		scanf("%s", board[r]); 

		for (int c = 0; c < n; c++) {
			if (board[r][c] == 'S' || board[r][c] == 'K') {
				pair<int, int> p(r, c);
				m.insert( make_pair(p, keyCount++) );
				v.push_back(p);
			}
		}
	}

	bool impossible = false;
	auto S = v.begin();
	initVisited();
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (board[r][c] == 'K' || board[r][c] == 'S') {
				bfs(0, r, c);
				if(!impossible && Q[m[*S]].size() < kn) impossible = true;
			}
		}
	}

	if(!impossible){
		printf("%d\n", prim(1));
	}else if(impossible){
		printf("-1\n");
	}
	
	return 0;
}
// 9%

//5 5
//0S00K
//11111
//K0K00
//0000K
//0000K






// S K K K K K
// K K K 1 K K
// 1 1 1 K K K 
// K K 1 K K K 
// K K K K K K 
// K K K K K K