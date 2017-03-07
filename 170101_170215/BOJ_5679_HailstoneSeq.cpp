#include<cstdio>

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		if(n == 0) return 0;

		// h(n) = h(n-1) / 2 // h(n-1) even
		// h(n) = 3* h(n-1) + 1 // odd
		int max = 0;
		while(1){
			max = (n>max)?n:max;
			if(n==1)break;
			(n%2==0)?n=n/2:n=3*n+1;
		}
		printf("%d\n",max);
	}
	return 0;
}