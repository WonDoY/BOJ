#include<cstdio>
int d, h, m, s, sec;
int main(){
	scanf("%d",&sec);
	d = sec/86400;
	h = (sec%86400)/3600;
	m = (sec%3600)/60;
	s = (sec%60);
	printf("%d %d %d %d",d,h,m,s);
	return 0;
}