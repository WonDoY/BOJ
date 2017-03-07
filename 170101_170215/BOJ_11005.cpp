#include<cstdio>
#define MAX 2000
char R[MAX] = {0,};
int N, B;

int main(){
	int rem;
	int cnt = 0;
	scanf("%d%d",&N,&B);
	while(N){
		rem=N % ( B );
		if(rem < B){
			//printf("\n\ninin	%d\n\n",rem);
			if (rem < 10){
				R[cnt] = rem +'0';
			}else if(rem >= 10){
				R[cnt] = (rem - 10) + 'A';	
			}
		}
		//printf("\n\n	%d\n\n",rem);
		cnt++;
		N = N / B;
	}
	for(int i = cnt-1 ;  i >= 0 ; i--){
		printf("%c",R[i]);
	}
	printf("\n");
	return 0;
}