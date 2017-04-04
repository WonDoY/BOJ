#include<cstdio>

int main(){
	int i,n,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i*=2){
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}