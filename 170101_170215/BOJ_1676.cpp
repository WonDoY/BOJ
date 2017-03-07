#include<cstdio>
#define LIMIT 1000000000000000
			  //9223372036854775807
int main(){
	int n;
	long long t = 1;
	int cnt = 0;
	scanf("%d",&n);
	while(n){
		if(n % 10==0 || n % 5 == 0 || n % 2 == 0){
			t = (t*n) % LIMIT;
		}
		while(t%10 == 0){
			cnt++;
			t = t/10;
		}
		//printf("t : %lld / n : %d, cnt : %d\n",t, n,cnt);
		n--;
	}
	printf("%d\n", cnt);
	return 0;
}