#include<cstdio>
#include<cmath>
int main(){
	long long n,m,tmpm;
	scanf("%lld%lld",&n,&m);
	tmpm=m; n--;
	while(n--) m*=tmpm;
	printf("%lld",m);
	return 0;
}