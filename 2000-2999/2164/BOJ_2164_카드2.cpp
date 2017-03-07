#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++) q.push(i);

	while(true){
		if(q.size() == 1){
			printf("%d",q.front());
			break;
		}
		q.pop();
		int back = q.front(); q.pop(); q.push(back);
	}
	return 0;
}