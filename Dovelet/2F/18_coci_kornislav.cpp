#include<cstdio>
int swap(int*x,int*y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return 0;
}

int main(){
	int a[4];
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			(a[i]>a[j]) ? swap(&a[i],&a[j]) :false;
		}
	}
	printf("%d",a[0]*a[2]);
	return 0;
}