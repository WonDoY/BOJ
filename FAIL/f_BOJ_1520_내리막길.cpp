#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

struct info{
	int r,c;
	info(int ir, int ic) : r(ir), c(ic) {}
};
VVI imap;
VVI dp;
int row, col;
int dir[4][2] = {{1,0} , {-1,0}, {0,1}, {0,-1}};

int max(int a, int b) {
	return (a>b)? a:b;
}

int dy(int r, int c){
	int &ret = dp[r][c];
	//if(ret > -1) return ret;

	int sum = 0;
	for(int i = 0 ; i < 4 ; i++){ // update 먼저
		int tr = r+dir[i][0];
		int tc = c+dir[i][1];
		if(0 <= tr && tr < row && 0 <= tc && tc < col){
			if(imap[tr][tc] > imap[r][c]){ // 현재 위치에서 비교
				// 현재 위치로 올 수 있는 경우
				// 현재 위치에서 갈 수 없는 경우
				int temp = (dp[tr][tc] != -1)? dp[tr][tc] : 0;
				if(dp[tr][tc] == -1){
					dp[tr][tc] = 0;
				}
				sum += dp[tr][tc]; 
			}
		}
	}
	
	for(int i = 0 ; i < 4 ; i++){
		int tr = r+dir[i][0];
		int tc = c+dir[i][1];
		if(0 <= tr && tr < row && 0 <= tc && tc < col){
			if(imap[tr][tc] < imap[r][c]){ // 다른 위치 값 update
				// 현재 위치에서 갈 수 있는 경우
				dp[tr][tc] = ret;
			}
		}
	}
	ret = max(ret, sum);
	return ret;
}

int main(){
	
	scanf("%d %d", &row, &col);
	imap = VVI(row, VI(col, 0) );
	dp = VVI(row, VI(col, -1) );
	for(int r = 0 ; r < row ; r++){
		for(int c = 0 ; c < col ; c++){
			scanf("%d", &imap[r][c]);
		}
	}

	dp[0][0] = 1;
	for(int r = 0 ; r < row ; r++){
		for(int c = 0 ; c < col ; c++){
			dp[r][c] = dy(r,c);
		}
	}

	printf("%d",dp[row-1][col-1]);
	return 0;
}