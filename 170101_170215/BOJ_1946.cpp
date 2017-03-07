#include<cstdio>
#include<algorithm>
#define MAX 100001
void solve(){
	std::pair<int, int> emp[MAX];
	int N; scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d", &emp[i].first, &emp[i].second);
	}
	std::sort(emp,emp+N);
	int res = 1;
	int countCondition = emp[0].second;
	for(int i = 1; i < N ; i++){
		if(countCondition > emp[i].second) countCondition = emp[i].second, res++;
	}
	printf("%d\n",res);

}
int main(){
	int tc = 0;
	scanf("%d",&tc);
	for(int i = 0 ; i < tc ; i++){
		solve();
	}
	return 0;
}