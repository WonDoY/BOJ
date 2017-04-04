#include<cstdio>

int SWAP(int *a,int *b) {
	int tmp=*a;
	*a=*b;
	*b=tmp;
	return 0;
} // void 형은 안되? 왜?

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	(a>b)?SWAP(&a,&b):false;
	(b>c)?SWAP(&b,&c):false;
	(a>b)?SWAP(&a,&b):false;
	printf("%d",b);
	return 0;
}