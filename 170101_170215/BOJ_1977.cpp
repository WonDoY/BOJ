#include<cstdio>
#include<cmath>
void solve(int min, int max){
	int temp = (int)sqrt((long double)min);
	int sum = 0, res = 0;
	if(temp*temp < min){
		temp++;
	}else if(temp==0){
		temp = 1;
	}

	for(int i = 0;(temp*temp)<=max;temp++,i++){
		sum+= (temp*temp) ;
		if(!i) res = temp*temp;
	}

	if(sum==0){
		printf("-1\n-1\n");
	}else{
		printf("%d\n%d\n",sum,res);
	}
}

int main(){
	int min,max;
	scanf("%d %d",&min,&max);
	solve(min,max);
	return 0;
}