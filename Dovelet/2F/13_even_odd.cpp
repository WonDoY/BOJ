#include<cstdio>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%s+%s=%s\n",
		(a&1)?"odd":"even" ,
		(b&1)?"odd":"even",
		((a+b)&1)?"odd":"even");
	printf("%s*%s=%s",
		(a&1)?"odd":"even" ,
		(b&1)?"odd":"even",
		((a*b)&1)?"odd":"even");
	return 0;

}