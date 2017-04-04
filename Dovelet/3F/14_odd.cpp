#include<cstdio>

int main(){
	int n,sum=0,min=100;
	for(int i =0 ; i<7 ; i++){
		scanf("%d",&n);
		if(n&1){
			sum+=n;
			if(min>n){
				min=n;
			}
		}
	}
	if(min==100){
		min = -1;
		printf("%d",min);
	}else{
		printf("%d\n%d",sum,min);
	}
	
	return 0;
}