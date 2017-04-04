#include<cstdio>
#define swap(a,b){int tmp=a;a=b;b=tmp;}
void SWAP(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	SWAP(&a,&b);
	printf("%d %d",a,b);
	return 0;
}

//#include<cstdio>
//int main(){
//	register int a,b;
//	scanf("%d%d",&a,&b);
//	printf("%d %d",b,a);
//	return 0;
//}