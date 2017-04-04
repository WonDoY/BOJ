#include<cstdio>

int main(){
	double time, min;
	int n;
	scanf("%d",&n);
	time = n;
	min = 0;
	switch(n){	
	case 11:
		min = -1; break;
	case 12:
		min = 0; break;
	default:
		//for(double i = 0 ; i < 60 ; i+=0.000001){		
		//	time+=0.0000000833333;
		//	min+=0.000001;
		//	//time+=0.00083;
		//	//min+=0.01;
		//	if(time > 32.727 ){
		//		printf("%.6lf %.6lf\n",time,min );
		//	}
		//	if(time==min) break;
		//}
		//break;
		min = (double)(60/11.0)*time;
	}
	

	if(min >= 0){
		printf("%.6lf",min);
	}else{
		printf("CAN'T SEE!");
	}


	return 0;
}