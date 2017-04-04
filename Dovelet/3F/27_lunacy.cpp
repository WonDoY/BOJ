#include<cstdio>

int main(){
	double n;
	while(1){
		scanf("%lf",&n);
		if(n<0) break;

		printf("Objects weighing %.2lf on Earth will weigh ",n);
		printf("%.2lf on the moon.\n",0.167*n);
	}

	return 0;

}