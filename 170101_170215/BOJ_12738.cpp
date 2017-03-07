
// lower bound 실제 구현할 것.
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> v;
int main(){
	scanf("%d", &n);
	int input = 0;
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &input);
		auto index = lower_bound(v.begin(),v.end(),input);
		if(index == v.end()){
			count++;
			v.push_back(input);
		}else if(index < v.end()){
			*index = input;
		}
	}
	printf("%d\n",count);
	return 0;
}