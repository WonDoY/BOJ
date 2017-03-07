#include<cstdio>
#include<vector>

using namespace std;


int make_height(int cnt){
	int ret = 1;
	while(cnt > 0) cnt = cnt >> 1, ret++;
	return ret;
}

int init(vector<int>& a, vector<int>& tree, int node, int start, int end){
	if(start == end) return tree[node] = a[start];
	
	int mid = (start+end)/2;
	int left = init(a, tree, 2*node, start, mid);
	int right = init(a, tree, 2*node + 1 , mid + 1 , end);
	return tree[node] = left + right;
}

int query(vector<int>& tree, int node, int start, int end, int left, int right){
	if(end < left || right < start) return 0;
	
	if(left <= start && end <= right) return tree[node];

	int mid = (start+end) / 2;
	return tree[node] = query(tree, 2*node, start, mid, left, right) +
		query(tree, 2*node + 1, mid+1, end, left, right);
}

int update(vector<int>& a, vector<int>& tree, int start, int end, int index, int diff){

}

int main(){
	int tc;
	for(scanf("%d", &tc) ; tc-- ; ){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> v(n);
		vector<int> tree(1 << make_height(n));
		for(int i = 0 ; i < n ; i++){
			tree[i+1] = m + i + (1 <<(n+m)) ;
		}

		init(v, tree, 1, 0, n-1);
		for(int i = 0 ; i < m ; i++){

		}
	}
	return 0;
}