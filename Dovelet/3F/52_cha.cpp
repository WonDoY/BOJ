#include<cstdio>
#define MAX 10000
int a[MAX];

int main(){
	
	scanf("%d%d",&a[0],&a[1]);
	printf("%d ",a[0]);
	for(int i = 1 ; a[i] >= 0 ; i++){ // for (condition!)
		printf("%d ",a[i]);		
		a[i+1] = a[i-1] - a[i];		
	}
	return 0;
}