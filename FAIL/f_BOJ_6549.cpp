#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAX 100000
typedef long long ll;
using namespace std;

ll result = 0;
ll a[MAX] = {0,};
ll endMax = 0;
int n; 
void bs(){
	ll start = 0;
	ll end = endMax;
	ll mid;
	while(end <= start){
		ll tempMax = 0;
		mid = (start+end)/2;
		ll sum = 0;
		for(int i = 0 ; i < n ; i++){
			if(a[i] >= mid){
				sum += mid;
			}else if(a[i] < mid){
				sum = 0;
			}

			if(tempMax < sum){
				tempMax = sum;
			}
		}
		
		if(tempMax < result){

		}else if(tempMax > result){

		}else if(tempMax == result){

		}
		result = max(tempMax, result);
	}
}
void init(){
}
int main(){
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
			endMax = max(endMax, a[i]);
		}
		bs();
		printf("%d\n",result);
	}

	return 0;
}