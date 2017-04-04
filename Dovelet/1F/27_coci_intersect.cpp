#include<cstdio>

int main(){
	int n, res;
	scanf("%d",&n);	
	res = n*(n-1)*(n-2)*(n-3)/24;
	printf("%d",res);
	return 0;
}