#include<cstdio>
#include<queue>

using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>, greater<ll>> pq;
int main(){
	int n; scanf("%d", &n);
	ll input;
	ll result = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &input);
		pq.push(input);
	}
	
	while(pq.size() > 0){
		ll acc = 0;
		ll acc1, acc2;
		if(pq.size() >0){
			acc1 = pq.top(); pq.pop();
		}
		if(pq.size() > 0){
			acc2 = pq.top(); pq.pop();
			acc = acc1 + acc2;
		}
		if(acc!=0){
			result += acc;
			pq.push(acc);
		}else{
			break;
		}
	}
	printf("%lld",result);

	return 0;
}
//// L1 a b c 
//// 2*L1 + a + b 
//// (2*L1 + a + b) + (2*L1+a+b)+ L1+c
//// f(n) = 2f(n-1) + a[n];
//// 더하고 나서 최소가 되는 것을 구해야하는 것...
//
//// 20 25 30 40 
//// 45 > 45 30 40
//// 45 45+30=75 > 75 40 
//// 45 75 75+40 > 115
//// 120 + 115 = 235 
//
//// 20 25 30 40
//// 45 > 45 30 40 >> 30 40 45
//// 45 + 70 >> 45 70
//// 45+70 45+70 >> 115
//// 230
//
//// 아... 그럼 최소가 되는 것을 항상 꺼내야 하는 것이 답이 되겠구나
//
//// 넣고 정렬하고 넣고 정렬하고 하면 -> n log n 이니까 터짐 
//// minheap을 사용해야한다. 
//#include<cstdio>
//#include<cstring>
//#define MAX 400000
//typedef long long ll;
//
//class minheap{
//private :
//	ll heap[MAX];
//	int size;
//public:	
//	minheap(){
//		//memset(heap,0x00000000ffffffff,MAX);
//		memset(heap, 0,MAX);
//		size = 0;
//	}
//	void swap(ll* v, ll* vv){
//		ll temp = *v;
//		*v = *vv;
//		*vv = temp;
//	}
//	void insert(ll input){
//		heap[size++] = input;
//		int tempHeap = size-1;
//		bool insertRun = false;
//		insertRun = (heap[(tempHeap-1)/2] > heap[tempHeap])? true : false; 
//		while(insertRun && tempHeap > 0){ // insert
//			insertRun = (heap[(tempHeap-1)/2] > heap[tempHeap])? true : false; 
//			if(insertRun){
//				swap(&heap[(tempHeap-1)/2],&heap[tempHeap]);
//			}
//			tempHeap = (tempHeap-1)/2;
//		}
//	}
//	ll pop(){
//		ll ret;
//		if(size == 0) ret = 0;
//		else if(size > 0){
//			ret = heap[0];
//			int tempHeap = 0;
//			heap[0] = heap[size-1];
//			//heap[size-1] = 0x00000000ffffffff;
//			heap[size-1] = 0;
//			while(tempHeap < size){
//				bool left, right;
//				left = false;
//				right = false;
//				if(heap[tempHeap] > heap[tempHeap*2+1] 
//				|| heap[tempHeap] > heap[tempHeap*2+2]){ 
//					// 오른쪽으로 뻗어나가는 가지 생각못함.
//					if(heap[tempHeap*2+1] <= heap[tempHeap*2+2] && heap[tempHeap*2+1] > 0){
//						left = true;
//						right = false;
//					}else if(heap[tempHeap*2+1] > heap[tempHeap*2+2] && heap[tempHeap*2+2] > 0){
//						left = false;
//						right = true;
//					}
//				}else{
//					tempHeap = size;
//				}
//				if(left){
//					swap(&heap[tempHeap], &heap[tempHeap*2+1]);
//					tempHeap = tempHeap*2+1;
//				}else if(right){
//					swap(&heap[tempHeap], &heap[tempHeap*2+2]);
//					tempHeap = tempHeap*2+2;
//				}else{
//					break;
//				}
//			}
//			if(size > 0) --size;
//		}
//		return ret;
//	}
//	bool isEmpty(){
//		if(size == 0){
//			return true;
//		}
//		return false;
//	}
//};
//
//int main(){
//	minheap* h = new minheap();
//	int n;
//	ll input;
//	ll result = 0;
//	scanf("%d", &n);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &input);
//		h->insert(input);
//	}
//	while(!h->isEmpty()){
//		ll a1 = h->pop();
//		ll a2 = h->pop();
//		ll acc = a1 + a2;
//		result += acc;
//		if(acc>0){
//			h->insert(acc);
//		}
//		printf("%lld %lld\n",acc, result);
//	}
//	printf("%lld", result);
//	
//	return 0;
//}
//
//
////#include<cstdio>
////#include<algorithm>
////#define MAX 100001
////using namespace std;
////typedef long long ll;
////ll a[MAX] = {0,};
////int main(){
////	int n;
////	scanf("%d", &n);
////	for(int i = 0 ; i < n ; i++) scanf("%lld",&a[i]);
////	sort(a,a+n);
////	ll result = a[0]+a[1];
////	for(int i = 2 ; i < n ; i++){
////		result = 2*result + a[i];
////	}
////	printf("%lld\n",result);
////	return 0;
////}
////// 9 % 틀렸습니다. 
