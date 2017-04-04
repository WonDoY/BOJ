#include<cstdio>
int i;
int main(){
	
	scanf("%d",&i);
	i=1000-i;
	printf("%d %d %d",(i/100),(i%100)/50,(i%50)/10);
	return 0;
}