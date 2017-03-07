#include<cstdio>
#define MAX 200
bool a[MAX][MAX] = {0,};
int n;
void solve(){
	int tmp = (n-1)*2;
	for(int r = 0 ; r < 2*n-1 ; r++){ 		
		for(int c = tmp-- ; c > r ; c--){
			a[r][c] = !a[r][c];
			a[2*(n-1)-r][c] = !a[2*(n-1)-r][c];
		}
		if(tmp==r) break;
	}
}
void print(){
	for(int r = 0 ; r < 2*n-1 ; r++){ 
		for(int c = 0 ; c < 2*n ; c++){
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