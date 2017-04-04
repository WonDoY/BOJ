#include<cstdio>

int main(){
	float N;
	scanf("%f",&N);
	printf("%d %.2f",(N>=0) ? int(N) : int(N)-1,(N>=0) ? N-(int)N : 1+N-(int)N);
	return 0;
}