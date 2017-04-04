#include<cstdio>

int main(){
	double a[3];
	double b[3];
	double res[3];
	double x,y,z;
	scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
	scanf("%lf%lf%lf",&b[0],&b[1],&b[2]);
	
	double min=555;
	int tmp=0;
	for(int i = 0 ; i < 3 ; i++){
		res[i]=a[i]/b[i];
		if(min>res[i]){
			min=res[i];
			tmp=i;
		}
	}
	min = b[tmp];
	double temp;
	for(int i = 0 ; i < 3 ; i++){
		b[i] = b[i]/min;
		temp = a[i]-a[tmp]*b[i] - (int)(a[i]-a[tmp]*b[i]);
		if(temp < 1 && temp > 0){
			printf("%.6lf ",a[i]-a[tmp]*b[i]);
		}else{
			printf("%d ",(int)(a[i]-a[tmp]*b[i]));
		}
	}
	
	//printf("%.6lf %.6lf %.6lf",a[0]-a[tmp]*b[0],a[1]-a[tmp]*b[1],a[2]-a[tmp]*b[2]);
}