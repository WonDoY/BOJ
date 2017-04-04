#include<cstdio>
#include<cmath>


int main(){
	/*
	// 1 2,000,000,000
	// 시간초과
	long long cnt, a,b,i,tmp;
	cnt = 0;
	scanf("%d%d",&a,&b);
	for(i = a; i<=b;i++){
		tmp=i;
		tmp=(long long)sqrt((double)tmp);
		(i!=tmp*tmp) ? cnt++ : false;
	}
	printf("%d",cnt);
	return 0;
	*/

	int cnt, a, b, i, tmp;
	
	scanf("%d%d",&a,&b);
	cnt = b-a+1; 
	for( i = (int)sqrt((float)a) ;i*i <= b ; i++){
		if(a<=i*i) cnt-- ;
		//printf("%d",cnt);
	}
	printf("%d",cnt);
	return 0;
}