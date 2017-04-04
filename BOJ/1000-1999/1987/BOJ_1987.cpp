#include<cstdio>
#define MAX 30
int movMax = 1;
int r, c;
char map[MAX][MAX] = {0,};
char det[MAX] = {0,};
int defCnt = 0;
int mov = 0;
void s(int arr[],int m, int x, int y){
	//printf("%c\n",map[x][y]);
	if(x<0 || (r-1) < x || y<0 || (c-1) < y){
		return ;
	}
	for(int idx = 0 ; idx < m ; idx++){
		if(arr[idx] == map[x][y]){
			return;
		}
	}
	arr[m++] = map[x][y];
	//printf("%c\n",map[x][y]);
	if(movMax < m){
		movMax = m;
	}
	
	s(arr, m, x-1, y);
	s(arr, m, x, y-1);
	s(arr, m, x+1, y);
	s(arr, m, x, y+1);
}

void solve(){
	int m = 0;
	int arr[MAX] = {0,};
	s(arr,m,0,0);
	printf("%d\n",movMax);
}

int main(){
	scanf("%d%d",&r,&c);
	for(int i = 0 ; i < r ; i++)scanf("%s",&map[i]);
	solve();
	return 0;
}