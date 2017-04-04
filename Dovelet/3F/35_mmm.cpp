#include<cstdio>

int main(){
	int n,s=0,M=-1,m=10000;
	for(int i = 0 ; i < 10 ; i++){
		scanf("%d",&n);
		s+=n;
		if(M<n){
			M=n;
		}
		if(m>n){
			m=n;
		}
	}
	printf("%d %d %d",s,M,m);
	return 0;

}