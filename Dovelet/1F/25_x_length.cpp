#include<cstdio>
#include<cmath>
#define PI 3.14159

int main(){
	double a,b;
	scanf("%lf%lf",&a,&b);

	printf("%.3f", sqrt(2.0)*(a+b) + PI*(a+b));

	return 0;
}