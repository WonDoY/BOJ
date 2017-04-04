#include<cstdio>
#include<algorithm>
#define MAX 100001
// 2*n 
long long f[MAX] = {1,3,0};
// 1 2 3 4 5 6 7 8 9 10
// 3 3*2 
// 2*1 : 인 경우 1마리 가능/ 0마리 가능 / 2+1 = 3 
// 2*2 : 인 경우 2마리 가능/ 1마리 가능 / 0 마리 가능 / 2+4+1 = 7
// 2*3 : 인 경우 3 / 2 / 1 / 0 / 2 + 8 + 6 + 1 f(n) = 2 + 1 + (f(n-1)+1) = 4 + 7
// 2*4 : 4 / 3 / 2 / 1 / 0 f(n) = 2 + 1 + 7 + 1 

// f(1) = 3 
// f(2) = 7 = 3*2 + 1
// f(3) = 17 = 7*2 + 3
// f(4) = 41 = 17*2 + 7
// f
// f(n) = f(n-1) * 2 + f(n-2)


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 2 ; i < MAX ; i++){
		f[i] = (2*f[i-1] + f[i-2])%9901;
	}
	//for(int i = 1 ; i <= n ; i++){
	//	printf("%lld ",f[i]);
	//}
	//printf("\n");
	printf("%lld",f[n]);

	return 0;
}