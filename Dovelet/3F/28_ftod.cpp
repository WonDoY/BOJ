#include<cstdio>

int main(){
	int n,k,t,p;
	scanf("%d%d%d",&n,&k,&t);
	printf("0.");
	for(int i = 0 ; i < t ; i++){
		n*=10;
		for(int j = 0 ; j <= 10 ; j++){
			//printf("\n%d %d\n",n,k*j);
			if(n<=k*j){
				j--;
				printf("%d",j);
				n-=k*j;
				break;
			}
		}		
	}
	return 0;
}