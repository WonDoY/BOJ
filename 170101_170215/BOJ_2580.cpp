#include<cstdio>
#include<cstring>
//#include<Windows.h>
#define MAX 10

int map[MAX][MAX] = {0,};
int ROW[MAX] = {0,};
int COL[MAX] = {0,};
int SIDE[MAX] = {0,};
bool res = false;

void printBoard(){
	//system("cls");
	for(int i = 1 ; i < MAX ; i++){
		for(int j = 1 ; j < MAX ; j++){
			printf("%d", map[i][j]);
			if(j != 9){	printf(" "); }
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
			if(SIDE[map[i][j]] > map[i][j]){
				return false;	
			}
		}
	}
	return true;
}
bool rowCondition(int r, int c){
		for(int i = 1 ; i < MAX ; i++){
		if(map[r][i] > 0){
			ROW[map[r][i]] += map[r][i];
			if(ROW[map[r][i]] > map[r][i]){
				return false;
			}
		}
	}
	return true;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
bool columnCondition(int r, int c){
	for(int i = 1 ; i < MAX ; i++){
			if(map[i][c] > 0){
			COL[map[i][c]] += map[i][c];
			if(COL[map[i][c]] > map[i][c]){
				return false;
			}
		}
	}
	return true;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
			if(board(row,col)){ // value correct
				if(col<9) back(row,col+1,n+1);
				else if(col==9) back(row+1,1,n+1);
				if(!res) map[row][col] = 0;	
			}else{ // value incorrect
				map[row][col] = 0;
			}				
		}else{
			if(col<9) back(row,col+1,n+1);
			else if(col==9) back(row+1,1,n+1);
			return ;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}


int main(){
	for(int i = 1 ; i < MAX ; i++){
		for(int j = 1 ; j < MAX ; j++){
			scanf("%d",&map[i][j]);
		}
	}
	back(1,1,0);
	printBoard();
	return 0;
}

				//printBoard();
				//printf("\n <%2d,%2d>, value <%2d> n <%2d>",row,col,value,n);
				//printCondition();