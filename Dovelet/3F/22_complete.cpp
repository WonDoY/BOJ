#include<cstdio>

int main(){
	int n,res=0 ; scanf("%d",&n);
	for(int i = 1 ; i < n ; i++){
		if(!(n%i))res+=i;
	}
	printf("%5d  %s",n,(n==res)?"PERFECT":(n<res)?"ABUNDANT":"DEFICIENT");
	return 0;
}