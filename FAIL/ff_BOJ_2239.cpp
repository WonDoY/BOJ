#include<cstdio>
#define MAX 10

int map[MAX][MAX] = {0,};
int ROW[MAX] = {0,};
int COL[MAX] = {0,};
int SIDE[MAX] = {0,};
bool res = false;

void printBoard(){
	for(int i = 1 ; i < MAX ; i++){
		for(int j = 1 ; j < MAX ; j++){
			printf("%d", map[i][j]);
			/*if(j != 9) printf(" ");*/
		}
		if(i<9) printf("\n");
	}
}
void boolInit(){
	for(int i = 1 ; i < MAX ; i++){
		ROW[i] = COL[i] = SIDE[i] = 0;
	}
}

bool sideCondition(int r, int c){
	int idx = 0;
	for(int i = 3*((r-1)/3)+1 ; i < 3*((r-1)/3+1)+1 ; i++){
		for(int j = 3*((c-1)/3)+1 ; j < 3*((c-1)/3+1)+1 ; j++){
			SIDE[map[i][j]] += map[i][j];
			if(SIDE[map[i][j]] > map[i][j])	return false;
		}
	}
	return true;
}
bool rowCondition(int r, int c){
	for(int i = 1 ; i < MAX ; i++){
		ROW[map[r][i]] += map[r][i];
		if(ROW[map[r][i]] > map[r][i]) return false;
	}
	
	return true;
}
bool columnCondition(int r, int c){
	for(int i = 1 ; i < MAX ; i++){
		COL[map[i][c]] += map[i][c];
		if(COL[map[i][c]] > map[i][c]) return false;
	
	}
	return true;
}
bool board(int r, int c){
	boolInit();
	if(!rowCondition(r,c))	return false;
	if(!columnCondition(r,c))return false;
	if(!sideCondition(r,c))	return false;
	return true;
}

void back(int row, int col, int n){
	if(n==81 || res){
		res = true;
		return ;
	}
	for( int value = 1 ; value < MAX ; value++){
		if(map[row][col] == 0){
			map[row][col] = value;
			if(board(row,col)){ 
				if(col<9) back(row,col+1,n+1);
				else if(col==9) back(row+1,1,n+1);
				if(!res) map[row][col] = 0;	
			}else{ 
				map[row][col] = 0;
			}				
		}else{
			if(col<9) back(row,col+1,n+1);
			else if(col==9) back(row+1,1,n+1);
			return ;
		}
        if(res) return ;
	}
}


int main(){
	char line[10];
	//for(int i = 1 ; i < MAX ; i++)
	//	for(int j = 1 ; j < MAX ; j++) scanf("%d",&map[i][j]);		
	
	for(int i = 1 ; i < MAX ; i++){
		gets(line);
		//printf("%s",line);
		for(int j = 1 ; j < MAX ; j++){
			map[i][j] = line[j-1]-'0';
		}
		//printf("\n");
	}
	back(1,1,0);
	printBoard();
	return 0;
}
//
//#include <stdio.h>
//#define MAX 9
//int arr[MAX+1][MAX+1];
//bool isFinished = false;
//
//int dfs(int m, int n) {
//	if(isFinished) return 0;
//	if(n > MAX) { // 오른쪽 끝 넘어가면 다음줄로 
//		m++;
//		n=1;
//	}
//	if(m > MAX) { // 마지막 줄 넘어가면 끝까지 잘 왔다는 뜻 
//		for(int i=1; i<=MAX; i++, printf("\n")) {
//			for(int j=1; j<=MAX; j++) {
//				printf("%1d", arr[i][j]);
//			}
//		}
//		isFinished=true;
//		return 0;
//	}
//	if(arr[m][n]==0) {
//		bool decision[MAX+1]={};
//		for(int j=1; j<=9; j++) {
//			decision[arr[m][j]]=true;
//			decision[arr[j][n]]=true;
//			decision[arr[((m-1)/3)*3 + (j-1)/3 + 1][((n-1)/3)*3 + (j-1)%3 + 1]]=true;
//		}
//		for(int i=1; i<=9; i++) {
//			if(decision[i]==true) continue;
//			arr[m][n] = i;
//			dfs(m, n+1);
//			arr[m][n] = 0;
//		}
//	} else {
//		dfs(m, n+1);
//	}
//}
//
//int main() {
//	for(int i=1; i<=MAX; i++) {
//		for(int j=1; j<=MAX; j++) {
//			scanf("%1d",&arr[i][j]);
//		}
//	}
//	dfs(1,1);
//}