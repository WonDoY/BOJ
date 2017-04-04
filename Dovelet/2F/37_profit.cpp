#include<cstdio>

int main(){
	float a,b,c, res;
	bool t = false;
	scanf("%f%f%f",&a,&b,&c);
	res = (a * ((100+b)/100) * ((100-c)/100)) - a;
	// printf("%f",res);
	(res>=0)?printf("%.0f",res):printf("loss");
	

	return 0;
}