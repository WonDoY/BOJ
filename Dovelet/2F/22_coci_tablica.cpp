#include<cstdio>
int swap(float*a,float*b,float*c,float*d){
	int tmp=*a;
	*a=*c;
	*c=*d;
	*d=*b;
	*b=tmp;
	return 0;
}
int main(){
	float a,b,c,d;
	float max;
	int cnt = 0, maxc = 0;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	max = a/c+b/d;
	for(int i = 0 ; i < 4 ; i++){
		cnt++;
		swap(&a,&b,&c,&d);
		if(max < a/c + b/d){
			maxc = cnt;
			max = a/c + b/d;
		}		
	}
	printf("%d",maxc);
	return 0;
}