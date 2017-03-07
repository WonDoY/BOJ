#include<cstdio>
#define RMAX 3072
#define CMAX 7000

char ch[RMAX][CMAX] = {0,};
bool f[RMAX][CMAX] = {0,};
int n;
int h, w;

void checking( int row,int col){
	ch[row][col] = ch[row+1][col-1] = ch[row+1][col+1] = ch[row+2][col-2] = ch[row+2][col-1] = ch[row+2][col] = ch[row+2][col+1] = ch[row+2][col+2] = '*';
}
void flag(int lv, int row, int col){ // 32 0 95
	if(lv == 3){
		f[row][col] = true;
	}
	else{
		flag(lv/2,  row , col );
		flag(lv/2,  row+lv/2, col-lv/2); 
		flag(lv/2,  row+lv/2, col+lv/2);
		#include<cstdio>
#define RMAX 3072
#define CMAX 7000

char ch[RMAX][CMAX] = {0,};
bool f[RMAX][CMAX] = {0,};
int n;
int h, w;

void checking( int row,int col){
	ch[row][col] = ch[row+1][col-1] = ch[row+1][col+1] = ch[row+2][col-2] = ch[row+2][col-1] = ch[row+2][col] = ch[row+2][col+1] = ch[row+2][col+2] = '*';
}
void flag(int lv, int row, int col){ // 32 0 95
	//if(lv == 0) return ;
	//if(row > n) return ; 
	//if(col < 0) return ;
	//if(col > w) return ;
	//f[row][col] = !f[row][col];
	//flag(lv-1,row+3, col-3); // 31 3 92 
	//flag(lv-1,row+3, col+3); // 31 3 98
	//return;
	//printf("%d\n",lv); 2^32
	// 나오긴 하는데.. 진짜 오래걸린다.
	if(lv == 3){
		f[row][col] = true;
		return;
	}
	else{
		flag(lv/2,  row , col );
		flag(lv/2,  row+lv/2, col-lv/2); 
		flag(lv/2,  row+lv/2, col+lv/2);
		return;
	}
}

void print(){
	for(int r = 0 ; r < h ; r+=3){
		for(int c = 0 ; c < w ; c++){
			if(f[r][c]){
				checking(r,c);
			}			
		}
	}
	for(int r = 0 ; r < h ; r++){

		if(r!=h-1)puts(ch[r]);
		else printf("%s",ch[r]);
	}
}
void init(){
	for(int r = 0 ; r < h ; r++)
		for(int c = 0 ; c < w ; c++)
			ch[r][c] = ' ';
}
int main(){
	scanf("%d", &n);
	h = n;
	w = 2*h-1;
	init();
	flag(n, 0, n-1); // 96/3 32 ,, 95
	print();
	return 0;
}



	}
}

void print(){
	for(int r = 0 ; r < h ; r+=3){
		for(int c = 0 ; c < w ; c++){
			if(f[r][c]){
				checking(r,c);
			}			
		}
	}
	for(int r = 0 ; r < h ; r++){

		if(r!=h-1)puts(ch[r]);
		else printf("%s",ch[r]);
	}
}
void init(){
	for(int r = 0 ; r < h ; r++)
		for(int c = 0 ; c < w ; c++)
			ch[r][c] = ' ';
}
int main(){
	scanf("%d", &n);
	h = n;
	w = 2*h-1;
	init();
	flag(n, 0, n-1); // 96/3 32 ,, 95
	print();
	return 0;
}


