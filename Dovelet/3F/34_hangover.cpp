#include<cstdio>

int main(){
	float res=2;
	float a=0,n=0;
	scanf("%f",&a);
	while(a>n){
		n+=(1/res);
		res++;		
	}
	printf("%.0f card(s)",res-2);
	return 0;
}