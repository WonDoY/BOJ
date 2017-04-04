#include<cstdio>

int main(){
	int n;scanf("%d",&n);
	while(n!=1){
		printf("%d ",n);
		if(n&1){
			n=3*n+1;
		}else{
			n/=2;
		}
	}
	printf("1");
	return 0;
}