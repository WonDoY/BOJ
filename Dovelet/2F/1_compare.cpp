#include<cstdio>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%c",(a>b)?'>':((a<b)?'<':'='));
	return 0;
}