#include<cstdio>

int main(){
	int n,k,t,f,res;
	scanf("%d%d%d%d",&n,&k,&t,&f);
	res = n;
	f-=n;
	while(f){		
		f-=k;
		f++;
		res+=k;
		//printf("%d\n",f);
	}
	printf("%d",res);

	return 0;
}