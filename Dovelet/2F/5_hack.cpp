#include<cstdio>

int main(){
	int r,e,c, t,u;
	char* x = "advertise\0",
		*y = "do not advertise\0",
		*z = "does not matter\0";	
	scanf("%d%d%d",&r,&e,&c);
	t = r; // 0
	u = e-c; // 30
	printf("%s", (t > u) ? y : ( (t < u)? x : z ) );
	return 0;
}