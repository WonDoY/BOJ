#include<cstdio>
int main(){
	float a,b;
	scanf("%f%f",&a,&b);
	a = (a/100)*b;
	printf("%.3f",-a);
	return 0;
}