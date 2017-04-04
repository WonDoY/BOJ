#include<cstdio>

int main(){
	int n,max=0,res=0;
	
	for(int i=1 ; i<=7;i++){
		scanf("%d",&n);
		if(max<n){
			max = n;
			res=i;
		}
	}
	printf("%d",res);
	return 0;
}