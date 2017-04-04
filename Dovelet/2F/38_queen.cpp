#include<cstdio>

int main(){
	long long n,m,res;
	scanf("%lld%lld",&n,&m);

	(n<m)?res=n:res=m;
	printf("%lld",res);

	return 0;
}