// cycle searching....
#include<cstdio>
#include<queue>
#define MAX 101
using namespace std;
// global Variable
bool visited[MAX];
bool save[MAX];
int a[MAX];
int n;
int maxCount = 0;
queue<int> q;
// End global Variable 
void init(){
	for(int i = 1 ; i <= n ; i++) visited[i] = false;
	while(!q.empty()) q.pop();
}
void copy(){
	for(int i = 1 ; i <= n ; i++) if(visited[i]) save[i] = true;
}
void print_result(){
	for(int i = 1 ; i <= n ; i++) if(save[i]) maxCount++;
	printf("%d\n",maxCount);
	for(int i = 1 ; i <= n ; i++) if(save[i]) printf("%d\n", i);
}

bool cycle(int start, int next){
	int ret = start;
	visited[start] = true;
	q.push(next);
	while(!q.empty()){
		int popnext = q.front();
		q.pop();
		if(popnext == ret){
			return true;
		} // The element start hav a Cycle;
		if(!visited[popnext]){
			visited[popnext] = true;
			q.push(a[popnext]);
		}
	}
	return false;
}
int main(){

	scanf("%d", &n); 
	// a[i] ~ i~ [1,n]
	for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; i++){
		int isCycle = cycle(i, a[i]);
		if(isCycle){
			copy();
			init();
		}else{
			init();
		}
	}
	print_result();
	return 0;
}