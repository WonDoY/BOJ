#include<cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int temp = n;
	int cnt = 1;
	if(temp < 10){
		temp = 10*temp + temp;
	}else{
		temp = (temp/10 + temp%10)%10 + 10*(temp%10);
	}
	//printf("%d\n",temp);
	while(temp != n){
		if(temp < 10){
			temp = 10*temp + temp;
		}else{
			temp = (temp/10 + temp%10)%10 + 10*(temp%10);
		}
		//printf("%d\n",temp);
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}