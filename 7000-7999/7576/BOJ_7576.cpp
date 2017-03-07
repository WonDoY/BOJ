#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX 1002
using namespace std;
queue<pair<int,int>> q1, q2;
int map[MAX][MAX] = {0,};
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int row, col;
void printMap(){
	for(int r = 0 ; r <= row+1 ; r++){
		for(int c = 0 ; c <= col+1 ; c++){
			printf("%2d",map[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	int count = 0;
	scanf("%d %d", &col, &row);
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			map[i][j] = -1;
		}
	}
	for(int r = 1 ; r <= row ; r++){
		for(int c = 1 ; c <= col ; c++){
			scanf("%d", &map[r][c]);
			if(map[r][c] == 1)	q1.push(make_pair(r,c));
		}
	}
	pair<int, int> temp;
	while(!q1.empty()){
		//printMap();
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		while(!q2.empty()){
			temp = q2.front();
			q2.pop();			
			for(int i = 0 ; i < 4; i++){
				int t_r = temp.first + dir[i][0];
				int t_c = temp.second + dir[i][1];
				if(map[t_r][t_c] == 0){
					map[t_r][t_c] = 1;
					q1.push(make_pair(t_r,t_c));
				}
			}
		}
		if(!q1.empty()) count++;
	}
	bool isRipen = true;
	for(int r = 1 ; r <= row ; r++){
		for(int c = 1 ; c <= col ; c++){
			if(map[r][c] == 0){
				isRipen = false;
				break;
			}
		}
	}
	printf("%d",(isRipen)?count:-1);
	return 0;
}
// 8 % 틀렸습니다.
// 100% 틀렸습니다.
// 100% 틀렸습니다. 
// 아 문제를 진짜 대충읽어버리는 구나 ........

// 아 미친 기본적인 BFS 문제를 9번틀리네