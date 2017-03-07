#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX 101010
#define COLOR 20
#define INF 0x0FFFFFFF
#define pb(a) push_back(a)
using namespace std;

vector<int> v[MAX];
int dp[MAX][COLOR];
bool visited[MAX];

//void printBoard(int n){
//	for(int i = 1 ; i <= n ; i++){
//		for(int j = 1 ; j < COLOR ; j++){
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

int mindp(int select, int except){
	int ret = INF;
	for(int i = 1 ; i < COLOR ; i++){
		if(i == except) continue;
		if(dp[select][i] < ret) ret = dp[select][i];
	}
	return ret;
}

void init(int select){
	for(int i = 1 ; i < COLOR ; i++) dp[select][i] = i;
}

void dynamic(int select){
	if(visited[select]) return;
	visited[select] = true;

	for(auto iter = v[select].begin() ; iter != v[select].end() ; iter++){
		if(!visited[*iter]){
			dynamic(*iter);
			for(int i = 1 ; i <= COLOR ; i++){
				dp[select][i] += mindp(*iter, i);
			}
		}
	}
}

int main(){
	
	int n;
	scanf("%d", &n);
	int v1, v2;
	for(int i = 1 ; i <= n ; i++){
		init(i);
	}

	for(int i = 0; i < n-1 ; i++){		
		scanf("%d %d", &v1, &v2);
		v[v1].pb(v2);
		v[v2].pb(v1);
	}
	dynamic(1);
	printf("%d\n",mindp(1,0));
	return 0;
}