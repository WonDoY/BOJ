#include<cstdio>

int main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		res += (2*(n-i)-1)*(2*i+1);
		//printf("%d %d\n",2*(n-i)-1,(2*i+1));
	}
	printf("%d",res);
	return 0;
}