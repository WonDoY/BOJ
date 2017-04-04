#include<cstdio>
int main(){
	int a,b,c;
	int x,y;
	scanf("%d%d%d",&a,&b,&c);
	x=b-a-1;
	y=c-b-1;
	if(x==0&&y==0){
		printf("%d",0);
	}else{
		printf("%d",(x>y)?x:y);
	}

	return 0;

}