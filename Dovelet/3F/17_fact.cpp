#include<cstdio>

int main(){
	int n,fac;
	scanf("%d",&n);
	fac=n;
	while(n--){
		if(n) fac*=n;
	}
	printf("%d",fac);
	return 0;
}