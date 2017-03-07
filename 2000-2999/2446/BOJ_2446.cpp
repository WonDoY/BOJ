#include<cstdio>
#define MAX 200
bool a[MAX][MAX] = {0,};
int n;
void solve(){
	int tmp = (n)*2-2; // 5 10-
	for(int r = 0 ; r < 2*n-1 ; r++){ 		
		for(int c = tmp-- ; c >= r ; c--){
			a[r][c] = !a[r][c];
			a[tmp+1][c] = !a[tmp+1][c];
		}
		if(r==n-1) break;
	}
	a[n-1][n-1] = !a[n-1][n-1];
}
void print(){
	for(int r = 0 ; r < 2*n-1 ; r++){ 
		for(int c = 0 ; c < 2*n ; c++){
			if(a[r][c]) printf("*");
			else{
				if(c>0){
					if(a[r][c-1]){
						if(r==2*n-2) break;
						printf("\n");
						break;
					}else{
						printf(" ");
					}
				}
				else{
					printf(" ");
				}
			}
		}
		//if(r != (2*(n-1))) printf("\n");
	}
}
int main(){
	
	scanf("%d",&n);
	solve();
	print(); 
	return 0;
}