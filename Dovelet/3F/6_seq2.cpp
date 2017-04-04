#include<cstdio>

int main(){
	int n,sum=0;
	scanf("%d",&n);

	for(int i=1; i<=n;i++){
		sum+=i;
		printf("1..%d %d\n",i,sum);
	}
	return 0;
}