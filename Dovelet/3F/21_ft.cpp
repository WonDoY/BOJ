#include<cstdio>

int main(){
	int n,cnt=0,sum=0,s=1;
	scanf("%d",&n);
	for(int i = 1; i<=n ; i++){
		if(!(n%i)){
			printf("%d ",i);
			cnt++;
			sum+=i;
			s*=i;
			s=s%10;
		}
	}
	printf("\n%d\n%d\n%d",cnt,sum,s);
	return 0;
}