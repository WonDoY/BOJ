#include<cstdio>

int main(){
	int a,b,x,l;
	double dist = 0;
	// 1<= a,b < x < l <= 40000
	// 부딪히기전까지 이동거리
	scanf("%d%d%d%d",&a,&b,&x,&l);
	dist = l/(double)(a+b)*x;
	
	
	printf("%.6lf",dist);
	return 0;
}