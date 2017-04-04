#include<cstdio>
int main(){
	int n, i;
	scanf("%d",&n); 
	n*=2;
	for(i = 1 ; i <= 100 ; i++){
		if((i+1)*(i) == n){
			break;
		}
	}
	printf("%d",i);
	return 0;
}