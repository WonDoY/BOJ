#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 20000
#define INF 9999
#define mp(a,b) make_pair(a,b)
using namespace std;
bool isNotPrime[MAX] = {1,1,0,};
int prime[MAX];
int pcnt;
bool visit[MAX];
void make_prime(){
	for(int i = 2 ; i < INF ; i++){
		int pmake = i;
		int interval = i;
		pmake += interval;
		while(pmake <= 10000){
			isNotPrime[pmake] = true;
			pmake += interval;
		}
	}
	for(int i = 1000; i < 10000 ; i++){
		if(!isNotPrime[i]){
			prime[pcnt++] = i;
		}
	}
}
int start, want;
queue<pair<int, int> > q;
int bfs(){
	q.push(mp(start,0));
	pair<int, int> p;
	while(!q.empty()){
		p = q.front();
		q.pop();
		
		int s = p.first;
		int c = p.second;
		if(s == want){
			return c;
		}
		int s1000 = s/1000;
		int s100 = (s/100)%10;
		int s10 = (s/10)%10;
		int s1 = s%10;
		//printf("%d // %d / %d-%d-%d-%d :: count : %d\n", want, s, s1000,s100,s10,s1,c);
		for(int i = 0 ; i < pcnt ; i++){
			int diff = 0;
			int p1000 = prime[i]/1000;
			int p100 = (prime[i]/100)%10;
			int p10 = (prime[i]/10)%10;
			int p1 = prime[i]%10;
			
			if(p1000 != s1000) diff++;
			if(p100  != s100 ) diff++;
			if(p10   != s10  ) diff++;
			if(p1    != s1   ) diff++;
			if(!visit[i] && diff == 1){
				visit[i] = true;
				q.push(mp(prime[i], c+1));
			}			
		}
	}
	return -1;
}
void init(){
	for(int i = 0 ; i < pcnt ; i++){
		visit[i] = 0;
	}
	while(!q.empty()){
		q.pop();
	}
}
int main(){
	make_prime();

	int tc;
	int result = -1;
	for(scanf("%d", &tc); tc-- ; ){
		init();
		scanf("%d %d",&start ,&want);
		result = bfs();
		if(result == -1) printf("Impossible\n");
		else printf("%d\n",result);
	}
	return 0;
}