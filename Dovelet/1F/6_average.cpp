#include<cstdio>
int a[4]; // 이게 더 빠름?
int main(){	
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	printf("%.2f",(a[0]+a[1]+a[2]+a[3])/(4.0));
	
	return 0;
}