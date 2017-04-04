#include<cstdio>

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	while(n>0){
		if(n&1){
			printf("%d ",cnt);
		}
		n =n >> 1;
		cnt++;
	}
	return 0;
}