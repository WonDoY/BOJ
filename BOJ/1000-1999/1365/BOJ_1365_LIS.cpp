#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int min(int a, int b){
	int ret = a; 
	if(ret > b) ret = b;
	return ret;
}
int main(){
	int n; 
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++) scanf("%d", &v[i]);

	int cnt = 0;
	vector<int> lis;
	for(auto iter = v.begin() ; iter != v.end() ; iter++){
		auto index = lower_bound(lis.begin(), lis.end(), *iter);
		if(index == lis.end()) cnt++, lis.push_back(*iter);
		else if(index < lis.end()) *index = *iter; 
	}

	printf("%d",min( n-cnt , cnt ) );
	return 0;
}