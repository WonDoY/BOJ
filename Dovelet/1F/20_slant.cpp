// 생각좀하고풀기
// 배수, 더주는 금액은?
// y = n * x + d;
// y0 = n * x0 + d;
// y1 = n * x1 + d;
// n = (y0-y1) / (x0-x1)
// n, d?
#include<cstdio>

int main(){
	int x[2],y[2], n, d;
	scanf("%d%d",&x[0],&y[0]);
	scanf("%d%d",&x[1],&y[1]);
	n = (y[0]-y[1]) / (x[0]-x[1]);
	(n < 0)? n=-n : false;
	(x[0]!=0) ? d = y[0] - n * x[0] : d = y[1] - n * x[1] ;
	printf("%d %d",n,d);
	
}