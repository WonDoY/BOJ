#include<cstdio>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b){
		int tmp=b;
		b=a;
		a=tmp;
	}
	for(int i=a; i<= b; i++){
		printf("%d ",i);
	}
	return 0;
}