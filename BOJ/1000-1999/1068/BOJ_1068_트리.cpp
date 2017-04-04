#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI T; // Tree
VI CN; // 1-vector CN ; The # of child of parent node 
VI P; // 1-vector P ; child node of Parent

void traversal(int del){
	for(auto iter = T[del].begin() ; iter != T[del].end() ; iter++){
		int node = *iter;
		CN[node] = -1;
		traversal(node);
	}
	return ;
}
int main(){
	int n;
	scanf("%d", &n);
	// 0 ~ n-1 ; n~[1,50]
	T = VVI(n);
	CN = VI(n);
	P = VI(n);
	for(int child = 0  ; child < n ; child++){
		int parent;
		scanf("%d", &parent); 
		if(parent!=-1){
			CN[parent]++; // parent node ; # of children node 
			T[parent].push_back(child);
			P[child] = parent; // WA1 ; add src
		}		
	}
	int del; scanf("%d", &del);

	CN[del] = -1;
	if(P[del] != -1) CN[P[del]]--; // WA1 ; add src
	traversal(del);

	int ans = 0;
	for(int i = 0 ; i < n ; i++) if(CN[i]==0) ans++;

	printf("%d",ans);
	return 0;
}
// 68? 70? WA

//4
//-1 0 1 2
//1
// ¿ÇÀº °ª 1 WA 0