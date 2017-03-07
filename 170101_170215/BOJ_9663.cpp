#include<cstdio>
#define MAX 15
int n;
int b[MAX];
int res = 0;
bool prom(int row){
	int tmprow = 1 ;
	while(tmprow < row){
		if(b[row] == b[tmprow] ||
			((b[row] - b[tmprow] > 0) ? b[row]-b[tmprow] : -(b[row]-b[tmprow])) == row - tmprow){//ї­==За
				return false;
		}
		tmprow++;
	}
	return true;
}

void backTracking(int row){
	for(int next = 1 ; next <= n ; next++){
		if(prom(row)){
			//printf("%d \n",row);
			if(row == n){
				/*for(int i = 1 ; i <= n ; i++)printf("%d ",b[i]);
				printf("\n");*/
				res++;
				return ;
			}
			else{
				b[row+1] = next;
				for(int i = row+2 ; i < MAX ; i++) b[i] = 0;
				backTracking(row+1);
			}
		}else{
			return;
		}
	}
}

int main(){
	scanf("%d", &n);
	backTracking(0);
	printf("%d\n",res);
	return 0;
}