#include<cstdio>

int main(){
	float a,b,c,d;
	float x,y;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	x = a-c;
	y = d-b;
	if(!x){
		printf("%s",(!y)? "many" : "none" );
	}else{
		printf("%.3f",y/x);
	}
	
	return 0;
}