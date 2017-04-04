#include<cstdio>

int main(){
	int a,b;
	int s,d;
	scanf("%d%d",&s,&d);
	// s = a+b;
	// d = max - min;
	// 차 
	// a+b 
	// max a a-b
	// max b b-a
	// 그냥 큰수 부터 출력
	// 그냥 무조건 a 가 크다 하자
	// d = a-b
	// s = a+b
	// s+d = 2*a;
	// 
	a=(s+d)/2;
	b=s-a;
	if(a+b==s && a-b==d && a>=0 && b>=0){
		printf("%d %d",a,b);
	}else{
		printf("impossible");
	}
	
	return 0;
}