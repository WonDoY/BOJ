#include<cstdio>
#include<cmath>
int main(){
	//M,N
	int M, N;
	int res = 0;
	int min = 0;
	bool t=false;
	scanf("%d%d",&M,&N);
	for(int i = M ; i <= N ; i++){
		if((int)sqrt((double)i)*(int)sqrt((double)i)==i){
			res+=i; 
			if(!t){
				t=true; min = i;
			}
		}
	}
	if(t){
		printf("%d\n%d",res,min);
	}else{
		printf("-1");
	}
	return 0;
}