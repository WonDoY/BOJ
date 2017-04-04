#include<cstdio>

int main(){
	float x,y;
	scanf("%f%f",&x,&y);
	if((int)x%5==0){
		printf("%.2f",(y-(x+0.50)>=0)? y-(x+0.50) : y );
	}else{
		printf("%.2f",y);
	}

	return 0;
}