#include<cstdio>
#include<algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

int n;
ll m;
ll input[MAX];
ll resultHeight = 0;
ll minH, maxH;

int condition(ll h){
	ll sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum+=(input[i]-h>0)?input[i]-h:0;
		if(m < sum) return -1;
	}
	if(m==sum) return 0;
	return 1;
}

void bs(){
	ll start = minH;
	ll end = maxH;
	ll height = (minH+maxH)/2;
	while(1){
		height = (minH+maxH)/2;
		if(maxH < minH) return ;
		switch(condition(height)){
		case -1:
			minH = height+1;
			resultHeight = height;
			break;
		case 0: 
			resultHeight = height;
			return;
		case 1: 
			maxH = height-1;
			break;	
		}
	}
}

int main(){
	minH = 0;
	maxH = 0;
	scanf("%d%lld",&n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &input[i]);
		if(maxH < input[i])	maxH = input[i];
	}
	bs();
	printf("%lld",resultHeight);
	return 0;
}


//#include<cstdio>
//#include<algorithm>
//#define MAX 1000001
//using namespace std;
//typedef long long ll;
//
//int n;
//ll m;
//ll input[MAX];
//ll resultHeight = 0;
//ll minH, maxH;
//
//int condition(ll h){
//	ll sum = 0;
//	for(int i = n-1 ; i >= 0 ; i--){
//		sum+=(input[i]-h>0)?input[i]-h:0;
//		if(m < sum) return -1; 
//		if( input[i] - h < 0 ) break;
//	}
//	if(m==sum) return 0;
//	return 1;
//}
//
//void bs(){
//	ll start = minH;
//	ll end = maxH;
//	ll height = (minH+maxH)/2;
//	while(1){
//		height = (minH+maxH)/2;
//		if(maxH < minH) return ;
//		switch(condition(height)){
//		case -1: // 요구 값보다 큼 0...10....20 
//			minH = height+1;
//			resultHeight = height;
//			break;
//		case 0: // 요구 값과 일치
//			resultHeight = height;
//			return;
//		case 1: // 요구 값보다 작음
//			maxH = height-1;
//			break;	
//		}
//	}
//}
//
//int main(){	
//	minH = 0;
//	maxH = 0;
//	scanf("%d%lld",&n, &m);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &input[i]);
//		if(maxH < input[i])	maxH = input[i];
//	}
//	sort(input,input+n); // 정렬때문에 더 걸리는 듯 하다.
//	bs();
//	printf("%lld",resultHeight);
//	return 0;
//}




//#include<cstdio>
//#include<algorithm>
//#define MAX 1000001
//using namespace std;
//typedef long long ll;
//
//int n;
//ll m;
//ll input[MAX];
//ll resultHeight = 0;
//ll minH, maxH;
//
//int condition(ll h){
//	ll sum = 0;
//	for(int i = 0 ; i < n ; i++){
//		sum+=(input[i]-h>0)?input[i]-h:0;
//		//printf("	%lld - %lld", m,sum);
//		if(m < sum) return -1;
//	}
//	if(m==sum) return 0;
//	return 1;
//}
//
//void bs(){
//	ll start = minH;
//	ll end = maxH;
//	ll height = (minH+maxH)/2;
//	while(1){
//		height = (minH+maxH)/2;
//		//printf("	%lld, [%lld,%lld]\n",height, minH, maxH);
//		if(maxH < minH) return ;
//		//printf("%lld, [%lld,%lld] need : %lld \n",height, minH, maxH,m);
//		switch(condition(height)){
//		case -1: // 요구 값보다 큼 0...10....20 
//			// 0... 10 .... 20 
//			// need 7
//			// 10 15 17 20 
//			minH = height+1;
//			resultHeight = height;
//			break;
//		case 0: // 요구 값과 일치
//			resultHeight = height;
//			//printf("out!");
//			return;
//		case 1: // 요구 값보다 작음
//			maxH = height-1;
//			break;	
//		}
//	}
//}
//
//int main(){
//	
//	minH = 0;
//	maxH = 0;
//	scanf("%d%lld",&n, &m);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &input[i]);
//		if(maxH < input[i]){
//			maxH = input[i];
//		}
//	}
//	bs();
//	printf("%lld",resultHeight);
//	return 0;
//}













//#include<cstdio>
//#include<algorithm>
//#define MAX 1000001
//using namespace std;
//
//typedef long long ll;
//ll m;
//int n;
//
//ll input[MAX];
//ll minHeight, maxHeight;
//ll resultHeight = 0;
//
//pair<ll, ll> dic[MAX];
//int dicIdx = 0;
//	// 10 15 17 20 
//	// min 10 max 20 
//	// 10 : 0 3*5 2*2 1*3 m < 7 resultHeight = 10;
//	// 15 : 0 0 2*2 3*1 m==7 (10 < 15)resultHeight = 15; break;
//	// 12 : 0 3*3 2*2 1*3 m < 16  
//	// if(resultHeight < height) resultHeight = height;
//
//
//bool binarySearch(ll min,ll max,int v){
//	int start = min, end = max;
//	int mid = (start+end)/2;
//	while(1){
//		if(start==end){
//			if(a[mid]==v){
//				return true;
//			}else{
//				return false;
//			}
//		}
//		if(start > end){
//			return false;
//		}
//		if(a[mid]==v){
//			return true;
//		}
//		else if(a[mid]<v){
//			start = mid+1; // 0 4 2 4 3 4
//			mid = (start+end)/2;
//		}
//		else if(a[mid]>v){
//			end = mid-1;
//			mid = (start+end)/2;
//		}
//	}
//	return false;
//}
//int main(){
//	minHeight = 0x7fffffffffffffff;
//	maxHeight = 0;
//	scanf("%d%lld", &n, &m);
//	for(int i = 0 ; i < n ; i++) scanf("%lld",&input[i]);
//	sort(input, input+n); 
//	// 10 15 17 20 
//	// min 10 max 20 
//	// 10 : 0 3*5 2*2 1*3 m < 7 resultHeight = 10;
//	// 15 : 0 0 2*2 3*1 m==7 (10 < 15)resultHeight = 15; break;
//	// 12 : 0 3*3 2*2 1*3 m < 16  
//	// if(resultHeight < height) resultHeight = height;
//	if(n>1){
//		//minHeight = input[0];
//		maxHeight = input[n-1];
//		resultHeight = 0;
//		// m 보다 크면 true 값바꿈.
//		// height
//
//		dicIdx = 0;
//		ll tmp = input[0];
//		dic[dicIdx].first = input[0];
//		dic[dicIdx].second = 0;
//		//   10 (14) 15 17 20      m 10 height (15-14) idx // 
//		//62 22 (10) 7  3  0 20	   height = 10 consume(c)
//		// height : 10 m < c true min = height+1 / max = max / height = (min+max)/2 ->15
//		// height : 15 m < c false / m > c / min = min / max = height-1 / height (min+max)/2 -> 11 14 -> 12
//		// height : 12 m 
//		//
//		//  4  3  2  1
//		// 0  1  2  3 총 갯수 4
//		for(int i = 0 ; i < n ; i++){
//			if(tmp != input[i]){
//				dic[++dicIdx].first = input[i];
//				dic[dicIdx].second = 0;
//			}else{
//				dic[dicIdx].second++;
//			}
//		}
//		dicIdx++;
//		for(int i = dicIdx-1 ; i > 0 ; i--){
//
//		}
//	}else{
//		maxHeight = input[0];
//	}
//
//
//	
//	return 0;
//}
//// 1,000,000 자료형을 받아 (input)
//// input 을 정렬한다. 
//// input으로 cut 값을 구한다. 
//// 20억...은 안되니까
//// 어차피 cut 값은 0....<<<<<<<<< .... n-1 이기 때문에
//// cut 값으로 !
//// binary search를 한다. 
//// 높이를 구한다. 
//
//// 10 15 17 20 (input-sorted )
//// 높이를 넣고 그것으로 자르며 확인한다. 
//// 최소 최대가 있으면.
//// 최소 0 , 최대 20 input 중 가장 큰것
//// 첫 mid 10
//// height 가 들어왔을 때 값을 자르는 것을... 
//// 높이의 최대 값은 1,000,000,000 보다 작거나 같다.
//// 이걸.. 저만치 큰 것에 쳐박으면 시간초과 100%
//
//// Q. 정렬된 자료를 어떻게 만들까? 
//// 이진탐색의 기준은 출력을 요구하는 height
//// height 마다 cut했을 값을 만들어야 한다. 
//// 그러면.. 1 로 컷 2 3 4 5 6 7 ...  max 을 만들어야 하는데 그게 말이되나...
//
//// 요구 7 
//// 1  2  3  4 
////  
//
//
//
//
