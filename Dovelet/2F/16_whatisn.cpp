#include<cstdio>

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	if(n<=5){
		cnt = (n/2)+1;
	}else{
		cnt = 5-((n+1)/2)+1;
	}
	printf("%d",cnt);
	return 0;
}