#include<cstdio>

int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		(n&1)?printf("%d\n",n-1):printf("No Solution!\n");
		scanf("%d",&n);
	}
	return 0;
}