#include<cstdio>

int main(){
	int C,K,t=1;
	scanf("%d%d",&C,&K);
	while(K--){
		t*=10;
	}
	K = C%t;
	C -= K;
	(K>=(t/2))? C += t : C ;
	printf("%d",C);
	return 0;
}