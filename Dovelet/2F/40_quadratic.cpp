#include<cstdio>
#include<cmath>
int main(){
	double a,b,c;
	double res,res1,res2;
	scanf("%lf%lf%lf",&a,&b,&c);
	

	res = (b*b) - (4*(a*c));
	res1 = ( -b-sqrt(res) ) / (2*a);
	res2 = ( -b+sqrt(res) ) / (2*a);
	if(res>0){
		printf("2\n");
		printf("%.3lf %.3lf",res1,res2);
	}else if(res<0){
		printf("0\n");
	}else if(res==0){
		printf("1\n");
		printf("%.3lf",res2);
	}
	



	return 0;
}