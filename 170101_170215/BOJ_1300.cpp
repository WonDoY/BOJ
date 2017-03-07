#include<cstdio>
typedef long long ll;
ll n;
ll k, kth;
void bs(){
	ll start = 1;
	ll end = 0x0000000fffffffff;
	ll mid;
	while(!(end < start)){
		mid = (start + end)/2;
		ll kthCount = 0;
		for(ll row = 1; row <= n ; row++){ // 각 행은 그 행의 배수들.
			kthCount += (n < (mid/row))? n : (mid/row);
		}
		//printf("\n%lld , %lld, %lld\n",kthCount, mid, end);
		if(kthCount >= k){ // 더 많이 count 되었으면 값을 줄인다.
			end = mid - 1;
			kth = mid;
		}else if(kthCount < k){ // 더 적게 count 되었으면 값을 늘린다.
			start = mid + 1;
		}
	}

}
// 1, 000, 000, 000
//10, 000, 000, 000
int main(){
	scanf("%lld%lld",&n,&k);
	bs();
	printf("%lld",kth);
	return 0;
}

//#include<cstdio>
//#include<algorithm>
//#define MAX 10000
//using namespace std;
//int n;
//long long k;
//long long arr[MAX*MAX] = {0,};
//int main(){
//	scanf("%d",&n);
//	for(int r = 1 ; r <= n ; r++){ // 1 2 3
//		for(int c = 1 ; c <= n ; c++){
//			arr[(r-1)*n + c - 1] = r*c; // 0 - 1 2 3 
//		}							// 3 - 1 2 3
//	}								// 6 - 1 2 3 
//	//for(int i = 0 ; i < n*n ; i++) printf("%lld ",arr[i]);
//	//printf("\n");
//	sort(arr,arr+n*n-1);
//	//for(int i = 0 ; i < n*n ; i++) printf("%lld ",arr[i]);
//	//printf("\n");
//	scanf("%lld",&k);
//	printf("%lld",arr[k-1]);
//	return 0;
//}