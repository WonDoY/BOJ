#include<cstdio>

int main(){
	int n,min=100;
	
	for(int i=0 ; i<7;i++){
		scanf("%d",&n);
		if(min>n){
			min = n;
		}
	}
	printf("%d",min);
	return 0;
}