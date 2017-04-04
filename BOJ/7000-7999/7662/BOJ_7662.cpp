// 마킹을......해서...... 풀어야..... 동기화.........되지.........
#include<cstdio>
#include<queue>
#include<cstring>
#define MAX 1000000
#define plli pair<long long, int>
using namespace std;
typedef long long ll;
bool mark[MAX] = {0,};

int main(){
	int tc = 0;
	scanf("%d", &tc);
	for(int i = 0 ; i < tc ; i++){
		int n;
		scanf("%d", &n);
		int markIndex = 0;
		priority_queue<plli, vector<plli>, less<plli> > pgreater;
		priority_queue<plli, vector<plli>, greater<plli> > pless;
		memset(mark, 0, MAX);
		for(int j = 0 ; j < n ; j++){

			char c = 0 ; ll input;
			scanf(" %c %lld",&c, &input);
			plli temp;
			switch(c){
			case 'I': 
				temp.second = markIndex++;
				temp.first = input;
				pgreater.push(temp);
				pless.push(temp);
				break;
			case 'D':
				if(input > 0){ // D 1 -> max 삭제

					if(!pgreater.empty()){
						while(mark[pgreater.top().second] == 1){
							pgreater.pop();
							if(pgreater.empty()) break;
						}
						if(!pgreater.empty()){
							mark[pgreater.top().second] = 1;
							pgreater.pop();
						}
					}
				}else if(input < 0){ // D -1 -> min 삭제
					if(!pless.empty()){
						while(mark[pless.top().second] == 1){
							pless.pop();
							if(pless.empty()) break;
						}
						if(!pless.empty()){
							mark[pless.top().second] = 1;
							pless.pop();
						}
					}
				}
				break;
			}
		}
		bool isEmpty = false;
		ll max, min;

		if(!pgreater.empty()){
			while(mark[pgreater.top().second] == 1){
				pgreater.pop();
				if(pgreater.empty()) break;
			}
		}
		if(!pless.empty()){
			while(mark[pless.top().second] == 1){
				pless.pop();
				if(pless.empty()) break;
			}
		}

		if(!pgreater.empty()){
			max = pgreater.top().first;
		}else{
			isEmpty = true;
		}

		if(!pless.empty()){
			min = pless.top().first;
		}else{
			isEmpty = true;
		}
		

		if(isEmpty){
			printf("EMPTY\n");
		}else{
			printf("%lld %lld\n", max, min);
		}

	}
	return 0;
}

//#include<cstdio>
//#include<queue>
//using namespace std;
//typedef long long ll;
//
//int main(){
//	int tc = 0;
//	scanf("%d", &tc);
//	for(int i = 0 ; i < tc ; i++){
//		int n;
//		scanf("%d ", &n);
//		priority_queue<ll,vector<ll>, less<ll>> pgreater;
//		priority_queue<ll,vector<ll>, greater<ll>> pless;
//		for(int j = 0 ; j < n ; j++){
//			char c = 0 ; ll input;
//			scanf("%c %lld ",&c, &input);
//			printf("\n== %c %lld ==\n", c, input);
//			switch(c){
//			case 'I': 
//				pgreater.push(input);
//				break;
//			case 'D':
//				if(input > 0){ // D 1 -> max 삭제
//					while(!pless.empty()){
//						printf("		pgreater in %lld\n", pless.top());
//						pgreater.push(pless.top());
//						pless.pop();
//					}
//					if(!pgreater.empty()){
//						printf("	pgreater pop : %lld\n",pgreater.top());
//						pgreater.pop();
//					}else{
//						printf("	pgreater not pop\n");
//					}
//				}else if(input < 0){ // D -1 -> min 삭제
//					while(!pgreater.empty()){
//						printf("		pless in %lld\n", pgreater.top());
//						pless.push(pgreater.top());
//						pgreater.pop();
//					}
//					if(!pless.empty()){
//						printf("	pless pop : %lld\n",pless.top());
//						pless.pop();
//					}else {
//						printf("	pless not pop\n");
//					}
//				}
//				break;
//			}
//		}
//		bool isEmpty = false;
//		ll max, min ;
//
//		while(!pgreater.empty()){
//			pless.push(pgreater.top());
//			pgreater.pop();
//		} // greater 가 비어있으면 less에 차있다. 
//
//		if(!pless.empty()){
//			min = pless.top();
//			while(!pless.empty()){
//				pgreater.push(pless.top());
//				pless.pop();
//			}
//			max = pgreater.top();
//		}
//		else{
//			isEmpty = true;
//		}
//
//		if(isEmpty){
//			printf("EMPTY\n");
//		}else{
//			printf("%lld %lld\n", max, min);
//		}
//
//	}
//	return 0;
//}
//
//
//
//
