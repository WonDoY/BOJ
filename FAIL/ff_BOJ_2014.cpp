#include <cstdio>
#include <queue>
#define MAX 100
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main(){
	ll prime[MAX];
	int K, N;
	ll result = 1;
	scanf("%d %d", &K, &N);
	for(int i = 0; i < K; i++) scanf("%lld", &prime[i]), pq.push(prime[i]); 

	for(int i = 0; i < N ; i++){
		if(pq.top() <= result){
			pq.pop();
			i--;
		}else{
			result = pq.top();
			pq.pop();
			for(int j = 0 ; j < K ; j++){
				if(result * prime[j] <= 0x000000007FFFFFFF && pq.size() <= 8000000){
					pq.push( result * prime[j] );
				}
			}
		}
	}
	printf("%lld", result);
	return 0;
}
// 16% 메모리초과

//#include <cstdio>
//#include <queue>
//#include <functional>
//#include <vector>
//#include <algorithm>
//#include <set>
//#define ll long long
//using namespace std;
//
//priority_queue<ll,vector<ll>,greater<ll>> pq;
//set<ll> visit;
//int main() {
//	int K, N; scanf("%d %d",&K,&N);
//	vector<ll> A(K, 0);
//	for (int i = 0; i < K; ++i) scanf("%lld ",&A[i]);
//	for (ll cur : A) {
//		pq.push(cur);
//		visit.insert(cur);
//	}
//	ll Cnt = 0,Max=A[K-1];
//	while (Cnt <= N) {
//		ll cur = pq.top();
//		Cnt++;
//		if (Cnt == N) {
//			printf("%lld\n",cur);
//			return 0;
//		}
//		pq.pop();
//		
//		for (ll ele : A) {
//			if (pq.size() >= N - Cnt  && Max < ele*cur) break;;
//			if (visit.find(ele*cur) == visit.end() && ele*cur < 3e9)
//			{
//				Max = Max > ele*cur ? Max : ele*cur;
//				pq.push(ele*cur);
//				visit.insert(ele*cur);
//			}
//			
//		}
//	}
//	return 0;
//}