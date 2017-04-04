#include<cstdio>

int main(){
	int a,b,c;
	float res;
	scanf("%d%d%d",&a,&b,&c);
	res = (2.5)*a + (2.0)*b + (0.5)*c;
	res *= 2;
	a = (int)res + (10-((int)res%10));
	printf("%d amperes",((int)res%10 != 0)? a : a-10);
	return 0;
}