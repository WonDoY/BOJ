#include<cstdio>
typedef long long lld;
// 0 1 2 3 4 5 6 7 8 9 10
int main(){
	lld a,b,v;
	scanf("%lld %lld %lld",&a ,&b, &v);
	
	lld start, end, day;

	// v +a -b
	// v day*(a-b) + a
	start = 0;
	end = 1000111000;
	lld result = 1000111000;

	while(start <= end){
		day = (start + end)/2;

		if(v <= day*(a-b) + a){
			result = (result > day+1)? day+1 : result ;
			end = day - 1;
		}else if(v > day*(a-b) + a){
			start = day + 1;
		}
	}
	printf("%lld",result);
	return 0;
}