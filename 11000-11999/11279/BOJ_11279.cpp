
// 우선순위 큐 구현... header queue -> priorityQueue
#include<cstdio>
#define MAX 400000
typedef long long ll;
ll max_heap[MAX] = {0,};
int heap_size = 0;
void swap(ll* v, ll* vv){
	ll temp = *v;
	*v = *vv;
	*vv = temp;
}
int main(){
	int N; 
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++){
		ll input = 0;
		scanf("%lld", &input);
		if(input == 0){ // input 이 0 display
			if(heap_size == 0) printf("0\n"); 
			else if(heap_size > 0){ 
				printf("%lld\n",max_heap[0]);
				int tempHeap = 0;
				max_heap[0] = max_heap[heap_size-1];
				max_heap[heap_size-1] = 0;

				while(tempHeap < heap_size){
					bool left, right;
					left = false;
					right = false;
					if(max_heap[tempHeap] < max_heap[tempHeap*2+1] || max_heap[tempHeap] < max_heap[tempHeap*2+2]){ 
						// 오른쪽으로 뻗어나가는 가지 생각못함.
						if(max_heap[tempHeap*2+1] >= max_heap[tempHeap*2+2]){
							left = true;
							right = false;
						}else if(max_heap[tempHeap*2+1] < max_heap[tempHeap*2+2]){
							left = false;
							right = true;
						}
					}else{
						tempHeap = heap_size;
					}
					if(left){
						swap(&max_heap[tempHeap], &max_heap[tempHeap*2+1]);
						tempHeap = tempHeap*2+1;
					}else if(right){
						swap(&max_heap[tempHeap], &max_heap[tempHeap*2+2]);
						tempHeap = tempHeap*2+2;
					}
				}
				if(heap_size > 0) --heap_size;

			}
		}else{
			max_heap[heap_size++] = input;
			int tempHeap = heap_size-1;
			bool insertRun = false;
			insertRun = (max_heap[(tempHeap-1)/2] < max_heap[tempHeap])? true : false; 
			while(insertRun && tempHeap > 0){ // insert
				insertRun = (max_heap[(tempHeap-1)/2] < max_heap[tempHeap])? true : false; 
				if(insertRun){
					swap(&max_heap[(tempHeap-1)/2],&max_heap[tempHeap]);
				}
				tempHeap = (tempHeap-1)/2;
			}
		}

	}
	return 0;
}
// 16% 틀렸습니다. 



//#include<cstdio>
//#include<algorithm>
//#define MAX 100001
//using namespace std;
//typedef long long ll;
//ll a[MAX] = {0,};
//int SIZE = 0;
//int main(){
//	int N; 	scanf("%d",&N);
//
//	for(int i = 0 ; i < N ; i++){
//		ll input = 0;
//		scanf("%lld", &input);
//		if(input == 0){
//			printf("%lld\n", (SIZE==0)? 0 : a[--SIZE]);
//		}else{
//			a[SIZE++] = input;
//			sort(a, a+SIZE);
//		}
//	}
//	return 0;
//}
// 8% 틀렸습니다.(시간초과)