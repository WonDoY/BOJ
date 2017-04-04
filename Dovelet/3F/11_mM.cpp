#include<cstdio>

int main(){
	int n,min=100,max=0;
	
	for(int i=0 ; i<7;i++){
		scanf("%d",&n);
		if(min>n){
			min = n;
		}
		if(max<n){
			max = n;
		}
	}
	printf("%d %d",max,min);
	return 0;
}