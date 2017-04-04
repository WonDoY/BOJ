#include<cstdio>
#include<algorithm>
#define MAX 200000
using namespace std;
typedef long long ll;
int n, c;
ll x[MAX];
ll result = 0;
ll min_Dist;
ll max_Dist;

void bs(){
	ll start = min_Dist;
	ll end = max_Dist;
	ll mid;
	while(!(end < start)){
		mid = (start + end) / 2;
		int count = 1;
		ll flag = x[0]; // 집의 첫 위치 // 가장멀리가 되려면 공유기는 처음과 끝에 설치되는 것은 당연.
		for(int i = 1 ; i < n ; i++) if(x[i]-flag >= mid) flag = x[i], count++;		
		if(count >= c) start = mid+1, result = mid; 
		else if(count < c) end = mid-1;
	}
}

int main(){
	scanf("%d%d",&n,&c);
	for(int i = 0 ; i < n ; i++) scanf("%lld",&x[i]);
	sort(x,x+n);
	min_Dist = x[0];
	max_Dist = x[n-1]-x[0];
	bs();
	printf("%lld",result);
	return 0;
}
// 20% 틀렸습니다.
// 20% 틀렸습니다.
// 20% 틀렸습니다.

//5 3
//1
//2
//8
//4
//9

//20 19
//1 2 8 4 9 
//13 15 19 38 120
//31 33 49 20 23
//40 11 34 21 51
//#include<cstdio>
//#include<algorithm>
//#define MAX 200000
//using namespace std;
//typedef long long ll;
//// n [2,200000]
//// c [2,n]
//// x[0..n-1] xi [1,1 000 000 000]
//// input x-> sort 
//int n, c;
//ll x[MAX];
//ll result;
//ll min_Dist;
//ll max_Dist;
//
//void printX(){
//	printf("\nX : ");
//	for(int i = 0 ; i < n ; i++){
//		printf("%2lld ",x[i]);
//	}
//	printf("\n");
//}
//
//void bs(){
//	ll start = min_Dist;
//	ll end = max_Dist;
//	ll mid;
//	result = 0;
//	
//	//printX();
//	while(!(end < start)){
//		mid = (start + end) / 2;
//		int FrontCount = 1;
//		int BackCount = 1;
//		int count = 0x00000000;
//		bool Fflag[MAX] = {0,};
//		bool Bflag[MAX] = {0,};
//		ll flag = x[0]; // 집의 첫 위치 // 가장멀리가 되려면 공유기는 처음과 끝에 설치되는 것은 당연.
//		Fflag[0] = 1;
//		for(int i = 1 ; i < n ; i++){
//			if(x[i]-flag >= mid){
//				flag = x[i];
//				Fflag[i] = 1;
//				FrontCount++;
//			}
//		}
//
//		//printf("	Front\nX : ");
//		//for(int i = 0 ; i < n ; i++) printf("%2c ",(Fflag[i])?'v':'-');
//		//printX();
//		
//		flag = x[n-1];
//		Bflag[n-1] = 1;
//		for(int i = n-2 ; i >= 0 ; i--){
//			if(flag - x[i] >= mid){
//				Bflag[i] = 1;
//				flag = x[i];
//				BackCount++;
//			}
//		}
//		//printf("	Back\nX : ");
//		//for(int i = 0 ; i < n ; i++) printf("%2c ",(Bflag[i])?'v':'-');
//		//printX();
//		// count가 더 크게 된 것과 적게 된 것이 존재.
//		// 앞과 뒤로 했을 시에 어떤 것을 비교 count 변수 값으로 받아야 하는가?
//		// 4
//		// 1 2 3 4   6    10       14
//		// v         v   v        v        
// 		//   v       v   v        v
//		// 5
//		// v         v             v
//		// v         v             v
//		// 2
//		// 1 2 3 4   6    10       14
//		// v   v     v    v        v 
//		//   v   v   v    v        v 
//		// 20
//		// 3     11    21 22    31    41 50
//		// v                    v          
//		//                v              v
//		
//		count = (FrontCount >= BackCount) ? FrontCount : BackCount;
//		//printf("[%lld <%lld> %lld] (%d/%d) <F: %d / B: %d>\n",start, mid, end, count, c, FrontCount, BackCount);
//		if(count >= c){ // count 된게 더 많아 그럼 크기를 늘여
//			start = mid+1; // 
//			result = mid; // 이부분이 잘못되었었음 if(count == c) result = mid; 라고 했음..
//		}else if(count < c){ // 요구공유기 수보다 count 된게 더 적어 그럼 크기를 줄여
//			end = mid-1;
//			//result = mid;
//		}
//	}
//}
//
//int main(){
//	scanf("%d%d",&n,&c);
//	for(int i = 0 ; i < n ; i++){ // Q 아근데 i++ ++i 차이가 있나 전합,후합 말고
//		scanf("%lld",&x[i]);
//	}
//	//printX();
//	sort(x,x+n);
//	//printX();
//	min_Dist = x[0];
//	max_Dist = x[n-1]-x[0];
//	//printf("%lld %lld\n",min_Dist, max_Dist);
//	bs();
//	printf("%lld",result);
//	return 0;
//}
//// 20% 틀렸습니다.
//// 20% 틀렸습니다.
//// 20% 틀렸습니다.
//
////5 3
////1
////2
////8
////4
////9
//
////20 19
////1 2 8 4 9 
////13 15 19 38 120
////31 33 49 20 23
////40 11 34 21 51