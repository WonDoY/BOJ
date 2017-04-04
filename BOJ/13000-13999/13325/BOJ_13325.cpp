// 1-2 1-3
// 2-3 2-4
// 2^20
#include<cstdio>
#define MAX 4040404
typedef long long ll;

ll weight[MAX] ;

ll ab(ll a){
	ll ret = a;
	return (ret > 0) ? ret : -ret;
}

int nodeCount(int depth){
	int ret = 1;
	while(depth--){
		ret *= 2;
	}
	return ret;
}

ll max2(ll a, ll b){
	ll ret = a;
	if(ret < b) ret = b;
	return ret;
}
int main(){
	int depth = 0;
	ll result = 0;
	scanf("%d", &depth);
	int count = nodeCount(depth+1);

	for(int i = 2 ; i < count ; i++){
		scanf("%lld", &weight[i]);
		result += weight[i];
	}

	for(int i = depth-1 ; i >= 0 ; i--){
		for(int parent = (1 << i) ; parent < (1 << (i+1)) ; parent++){
			int child_1 = 2 * parent + 0;
			int child_2 = 2 * parent + 1; 
	
			if(weight[child_1] == weight[child_2]){
				weight[parent] += weight[child_1];
			}else if(weight[child_1] != weight[child_2]){
				result += ab(weight[child_1] - weight[child_2]); 
				weight[parent] +=  max2( weight[child_1] , weight[child_2] );
			}
		}
	}

	printf("%d",result);
	return 0;
}
// 2
//        0
//		 1 1000
// 1 1		1000 1000



