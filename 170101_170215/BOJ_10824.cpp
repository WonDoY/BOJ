#include<cstdio>
int main(){
	long long a,b,c,d;
	scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
	int tempb = b;
	int tempd = d;
	if(tempb == 0){
		a*=10;
	}else{
		while(tempb > 0){
			tempb /= 10;
			a *= 10;
		}
		a += b;
	}
	if(tempd == 0){
		c*=10;
	}else{
		while(tempd > 0){
			tempd /= 10;
			c *= 10;
		}
		c += d;
	}
	printf("%lld",a+c);
}