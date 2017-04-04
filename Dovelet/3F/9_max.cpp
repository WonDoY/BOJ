#include<cstdio>

int main(){
	int n,max=0;
	
	for(int i=0 ; i<7;i++){
		scanf("%d",&n);
		if(max<n){
			max = n;
		}
	}
	printf("%d",max);
	return 0;
}