#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
	int tc;
	for(scanf("%d",&tc); tc--; ){
		int numOfBuild, numOfRule;
		scanf("%d %d", &numOfBuild, &numOfRule);
		VVI building = VVI(numOfBuild+1, VI(3, 0));
		VVI adj = VVI(numOfBuild+1,VI(0,0));
		
		for(int i = 1 ; i <= numOfBuild ; i++) scanf("%d", &building[i][1]); 
		
		for(int i = 0 ; i < numOfRule ; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			building[v][0]++;
		}

		queue<int> Q;
		for(int i = 1 ; i <= numOfBuild ; i++){
			if(building[i][0] == 0){
				Q.push(i);
				building[i][2] = building[i][1];
			}
		}

		while(!Q.empty()){
			int here = Q.front(); Q.pop();
			
			for(auto iter = adj[here].begin() ; iter != adj[here].end() ; iter++){
				int there = *iter;
				if(building[there][2] < building[there][1] + building[here][2]){
					building[there][2] = building[there][1] + building[here][2];
				}

				building[there][0]--;
				if(building[there][0] == 0) Q.push(there);
			}
		}

		int want;
		scanf("%d", &want);
		printf("%d\n", building[want][2]);
	}
	return 0;
}