#include<cstdio>
#define MAX 10000
bool a[MAX][MAX] = {0,};
int n;

void solve(){
	for(int r = 0 ; r < n ; r++){
		for(int c = 0 ; c < n ; c++){
			for(int t = 3 ; t <= n ; t*=3){
				if( (t/3) <= (r%t) && (r%t) < 2*(t/3) && (t/3) <= (c%t) && (c%t) < 2*(t/3)  ){
					if(!a[r][c]){
						a[r][c] = !a[r][c];
					}
				}
			}
		}
	}

} // 수정가능할듯...

void print(){
	for(int r = 0 ; r < n ; r++){
		for(int c = 0 ; c < n ; c++){
			(a[r][c])?printf(" "):printf("*");
		}
		if(r!=n-1) printf("\n");
	}
}
int main(){
	scanf("%d",&n);
	solve();
	print();
	return 0;
}