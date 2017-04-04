#include<cstdio>

int main(){
	//1,3,5
	char *a = "enjoy\0",
		*b = "oops\0";
	int i;
	scanf("%d",&i);

	printf("%s",(i & 1) ? ((i != 7)? a: b) : b);

	return 0;
}