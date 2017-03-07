#include<cstdio>
#define MAX 2000000
bool isNotPrime[MAX] = {1,1,0}; // 에효 이거 왜 체크 안해놨냐
void make_prime(){
	for(int i = 2 ; i < MAX ; i++){
		int pmake = i;
		int interval = i;
		pmake += interval;
		while(pmake <= MAX){
			isNotPrime[pmake] = true;
			pmake += interval;
		}
	}
}

int main(){
	int m, n;
	make_prime();
	scanf("%d %d", &m, &n);
	for(int i = m ; i <= n ; i++){
		if(!isNotPrime[i]){
			printf("%d\n",i);
		}
	}
	return 0;
}
// 100% 틀렸습니다...........!!!!!!!!!!

//#include<cstdio>
//
//using namespace std;
//
//int prime[1000001];
//
//int main() {
//
//	int m, n;
//	scanf("%d %d", &m, &n);
//
//	prime[1] = true;
//	for (int i = 2; i <= n; i++) {
//		if (prime[i] == false) {
//			for (int j = 2; i*j <= n; j++) {
//				if (prime[i*j] == false)
//					prime[i*j] = true;
//			}
//		}
//	}
//
//	for (int i = m; i <= n; i++) {
//		if (prime[i] == false) {
//			printf("%d\n", i);
//		}
//	}
//
//}