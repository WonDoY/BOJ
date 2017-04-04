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
		ll flag = x[0]; // ���� ù ��ġ // ����ָ��� �Ƿ��� ������� ó���� ���� ��ġ�Ǵ� ���� �翬.
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
// 20% Ʋ�Ƚ��ϴ�.
// 20% Ʋ�Ƚ��ϴ�.
// 20% Ʋ�Ƚ��ϴ�.

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
//		ll flag = x[0]; // ���� ù ��ġ // ����ָ��� �Ƿ��� ������� ó���� ���� ��ġ�Ǵ� ���� �翬.
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
//		// count�� �� ũ�� �� �Ͱ� ���� �� ���� ����.
//		// �հ� �ڷ� ���� �ÿ� � ���� �� count ���� ������ �޾ƾ� �ϴ°�?
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
//		if(count >= c){ // count �Ȱ� �� ���� �׷� ũ�⸦ �ÿ�
//			start = mid+1; // 
//			result = mid; // �̺κ��� �߸��Ǿ����� if(count == c) result = mid; ��� ����..
//		}else if(count < c){ // �䱸������ ������ count �Ȱ� �� ���� �׷� ũ�⸦ �ٿ�
//			end = mid-1;
//			//result = mid;
//		}
//	}
//}
//
//int main(){
//	scanf("%d%d",&n,&c);
//	for(int i = 0 ; i < n ; i++){ // Q �Ʊٵ� i++ ++i ���̰� �ֳ� ����,���� ����
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
//// 20% Ʋ�Ƚ��ϴ�.
//// 20% Ʋ�Ƚ��ϴ�.
//// 20% Ʋ�Ƚ��ϴ�.
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