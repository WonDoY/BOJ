//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//priority_queue<pair<int,int> > pq[10000];
//int main(){
//	int V,E;
//	int v1,v2,w;
//	int result = 0;
//	scanf("%d %d",&V,&E);
//
//	for(int i=0;i<E;i++){
//		scanf("%d %d %d",&v1,&v2,&w);
//		pq[v1].push(make_pair(-w, v2));
//		pq[v2].push(make_pair(-w, v1));
//	}
//
//	pair<int,int> p;
//	int count = 1;
//	while(!pq[1].empty()){
//		p = pq[1].top();
//		pq[1].pop();
//
//		result += -p.first;
//		count++;
//
//		while(!pq[p.second].empty()){
//			pq[1].push(pq[p.second].top());
//			pq[p.second].pop();
//		}
//		if(count == V)break;
//	}
//	printf("%d\n",result);
//	return 0;
//}
//// 9% Æ²·È½À´Ï´Ù.

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int,int> > pq[10001];

int main(){

	int V,E;   
	int v1,v2,w;   
	int result=0;
	scanf("%d%d",&V,&E);

	vector<bool> visited(V+1,false);

	for(int i=0;i<E;i++){
		scanf("%d%d%d",&v1,&v2,&w);
		pq[v1].push(make_pair(-w,v2));
		pq[v2].push(make_pair(-w,v1));
	}

	pair<int,int> p;

	visited[1]=true;
	while(!pq[1].empty()){

		if(visited[pq[1].top().second]){
			pq[1].pop(); continue;
		}
		p=pq[1].top();
		pq[1].pop();

		visited[p.second]=true;
		result+= -p.first;

		while(!pq[p.second].empty()){
			pq[1].push(pq[p.second].top());
			pq[p.second].pop();
		}
	}
	printf("%d\n",result);

	return 0;
}