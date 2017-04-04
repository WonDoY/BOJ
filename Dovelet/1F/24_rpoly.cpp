#include<cstdio>
#include<cmath>
#define PI 3.141592653589
double rad, res; // 7
int n;

int main(){
	scanf("%lf%d",&rad, &n);
	res = n*(0.5)*(pow(rad,2)*sin(2*PI/n));

	printf("%.3lf\n",res);
	return 0;
}