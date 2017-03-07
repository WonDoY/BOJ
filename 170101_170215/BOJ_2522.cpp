#include<cstdio>
#define MAX 200
bool a[MAX][MAX] = {0,};
int n;
void solve(){
	int tmp = n-2;
	for(int r = 0 ; r < 2*n-1 ; r++){ 		
		for(int c = tmp-- ; c >= 0 ; c--){
			a[r][c] = !a[r][c];
			a[2*n-2-r][c] = !a[2*n-2-r][c];
		}
		if(n%2==1){
			if(tmp==r+1) break;
		}
		if(n%2==0){
			if(tmp==r)break;
		}
	}
}
void print(){
	for(int r = 0 ; r < 2*n-1 ; r++){ 
		for(int c = 0 ; c < n ; c++){
			if(a[r][c]) printf(" ");
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