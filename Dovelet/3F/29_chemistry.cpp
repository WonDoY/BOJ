#include<cstdio>

int main(){
	float a,b;
	scanf("%f",&a);
	while(1){
		b=a;
		if(a==999){ break; }
		scanf("%f",&a);		
		if(a==999){ break; }
		b=a-b;
		printf("%.2f\n",b);
	}
	printf("End of Output");

	return 0;
}