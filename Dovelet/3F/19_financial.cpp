#include<cstdio>
// float ¿¡·¯
int main(){
	double n,res;
	res =0;
	for(int i = 0 ; i < 12 ; i++){
		scanf("%lf",&n);
		res+=n;
	}
	printf("$%.2lf",res/12);
	return 0;
}