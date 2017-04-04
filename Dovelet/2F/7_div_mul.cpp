#include<cstdio>

int main(){
	int m, n;
	bool t = false;
	scanf("%d%d",&m,&n);

	for(int i = -100 ; i <= 100 ; i++){
		if(m*i == n) t=true;
		if(n == 0) t=true;
	}

	printf("%d %s %d",m,(t)?"|" : "!|" ,n);
	return 0;
}