#include<cstdio>
#define MAX 100
int main(){
	int n;
	int a[3];
	int min = 100;
	int r[2] ;
	int re;
	scanf("%d",&n);
	for(int i = 0 ; i < 3 ; i++){
		scanf("%d",&a[i]);
		if(min>a[i])min=a[i];
		
	}
	r[0] = n-a[0];
	r[1] = n-a[1];
	re = a[2]-(r[0]+r[1]);
	if(re<0) re=0;
	printf("%d %d",min, re);
	return 0;
}