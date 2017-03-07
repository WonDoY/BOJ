#include<cstdio>
#define MAX 200
bool a[MAX][MAX] = {0,};
int n;
void solve(){
	for(int r = 0 ; r < 2*n-1 ; r++){ 		
		for(int c = 0 ; c < r+1 ; c++){
			a[r][c] = !a[r][c];
			a[2*n-2-r][c] = !a[2*n-2-r][c];
		}
	}
}
void print(){
	for(int r = 0 ; r < 2*n-1 ; r++){ 
		for(int c = 0 ; c < n ; c++){
			if(a[r][c]){
				if(r==2*n-2) break;
			}
			else printf("*");
		}
		if(r != (2*(n-1))) printf("\n");
	}
}
int main(){

	scanf("%d",&n);
	solve();
	print(); 
	return 0;
}