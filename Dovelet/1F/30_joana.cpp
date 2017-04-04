// 같이 사용할 변수는 형변환도 같은 것으로!
#include<cstdio>

int main(){
	long long n, k;
	long long out = 0;
	scanf("%lld",&n);
	k = (long long)(n/2)+1;
	(n==3) ? out = 15 : (n==1) ? out = 1: out = 3*(5+(k-2)*6+((k-1)*(k-2)/2)*4 ) ;
	
	printf("%lld",out);

	return 0;
}