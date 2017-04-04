#include<cstdio>
#include<vector>
#include<cstring>
#define MAX 3000
using namespace std;
bool prime[MAX] = {1,1,0,};
bool exception[60];
int count;
vector<int> v;
void primeInit(){
	for(int i = 2 ; i < MAX ; i++){
		for(int j = i+i ; j < MAX ; j += i){
			prime[j] = true;
		}
	}
}

bool dfs(int start){
	int temp1 = 0;
	int temp1_index = 0;
	int temp2 = 0;
	int temp2_index = 0;
	for(int i = start ; i < count ; i++){
		if(!exception[i]){
			if(!temp1){
				temp1 = v[i];
				temp1_index = i;
				continue;
			}
			if(!temp2){
				temp2 = v[i];
				temp2_index = i;
			}
		}
		if(prime[temp1+temp2]){
			exception[temp1_index] = true;
			exception[temp2_index] = true;
			dfs(start);
		}
	}
}

int main(){
	primeInit();
	
	scanf("%d", count);
	
	vector<int> result;
	for(int i = 0 ; i < count ; i++){
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	for(int i = 1 ; i < count ; i++){
		memset(exception, 0, sizeof(exception) );
		if(prime[v[0]+v[i]){
			exception[0] = true;
			exception[i] = true;
			if(dfs(0+1)){
				result.push_back(v[i]);
			}
		}
	}

	return 0;
}