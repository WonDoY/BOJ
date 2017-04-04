// 생각좀
#include<cstdio>

int main(){
	// k개핵 분열
	// 안정/불안정
	int k,n,res=0;
	const int MeV=100;
	scanf("%d%d",&k,&n);
	res = (n-1)/(k-1)*MeV;
	printf("%d",res);
	
	return 0;
}