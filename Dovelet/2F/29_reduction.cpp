#include<cstdio>
#include<cmath>
int swap(float *x, float *y){
	float tmp = *x;
	*x= *y;
	*y= tmp;
	return 0;
}
int main(){
	float a[2],b[2];
	float x,y;
	for(int i = 0 ; i < 2 ; i++) scanf("%f",&a[i]);
	for(int i = 0 ; i < 2 ; i++) scanf("%f",&b[i]);
	(a[0]>a[1])?swap(&a[0],&a[1]) : false; // 큰 게 더 뒤에 
	(b[0]>b[1])?swap(&b[0],&b[1]) : false;

	x=a[0]/b[0];
	y=a[1]/b[1];
	if(x<=1&&y<=1){
		x=y=1;
	}
	(x>=y)?printf("%.0f%%",floor((1/x)*100)):printf("%.0f%%",floor((1/y)*100));
	return 0;
}