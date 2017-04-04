#include<cstdio>

int main(){
	float a,b,c,d;
	float x,y;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	x=a/b; y=c/d;
	
	printf("%d",(x>y)? 1 :((x<y)? -1:0));
}