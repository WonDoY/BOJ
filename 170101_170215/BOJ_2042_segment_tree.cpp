#include<cstdio>
#include<vector>
#define vll vector<ll>
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int make_height(int cnt);

ll init(vll& a, vll& tree, int node, int start, int end);
ll sum(vll& tree, int node, int node_s, int node_e, int left, int right);
void update(vll& tree, int node, int node_s, int node_e, int index, ll diff);

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vll v(n);
	vll tree(1 << make_height(n));
	ll in = 0;
	for(int i = 0 ; i < n ; i++) scanf("%lld", &v[i]);

	int command;
	init(v, tree, 1, 0, n-1);
	for(int i = 0 ; i < m+k ; i++){
		//scanf("%d %d %d", &command, &a, &b);
		scanf("%d", &command);
		if(command == 1){ // swap && update
			int a;
			ll b;
			scanf("%d %lld", &a, &b);
			ll diff = b - v[--a];
			v[a] = b;
			update(tree, 1, 0, n-1, a, diff);
		}
		else if(command == 2){ // sum
			int a,b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", sum(tree, 1, 0, n-1, a-1, b-1) );
		}
	}
	return 0;
}


int make_height(int cnt){
	int ret = 1;
	
	while(cnt > 0){
		ret++;
		cnt = cnt >> 1;
	}
	return ret;
}

ll init(vll& a, vll& tree, int node, int start, int end){
	if(start == end) return tree[node] = a[start];
	else{
		return tree[node] = init(a, tree, node*2, start, (start+end)/2)
			+ init(a, tree, node*2 + 1 , (start+end)/2 + 1 , end);
	}
}

ll sum(vll& tree, int node, int node_s, int node_e, int left, int right){
	if( node_e < left || right < node_s ) return 0;
	if( left <= node_s && node_e <= right ) return tree[node];
	return sum(tree, node*2, node_s, (node_s + node_e)/2, left, right)
		+ sum(tree, node*2 + 1, (node_s + node_e)/2 + 1, node_e, left, right);
}

void update(vll& tree, int node, int node_s, int node_e, int index, ll diff){
	if(index < node_s || node_e < index) return ;
	tree[node] = tree[node] + diff;
	if(node_s != node_e){
		update(tree, node*2, node_s, (node_s + node_e)/2 , index, diff);
		update(tree, node*2 + 1, (node_s + node_e)/2 + 1, node_e , index, diff);
	}
}


//#include <cstdio>
//#include <cmath>
//#include <vector>
//using namespace std;
//long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
//	if (start == end) {
//		return tree[node] = a[start];
//	} else {
//		return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
//	}
//}
//void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
//	if (index < start || index > end) return;
//	tree[node] = tree[node] + diff;
//	if (start != end) {
//		update(tree,node*2, start, (start+end)/2, index, diff);
//		update(tree,node*2+1, (start+end)/2+1, end, index, diff);
//	}
//}
//long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
//	if (left > end || right < start) {
//		return 0;
//	}
//	if (left <= start && end <= right) {
//		return tree[node];
//	}
//	return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
//}
//
//int make_height(int cnt){
//	int ret = 1;
//	
//	while(cnt > 0){
//		ret++;
//		cnt = cnt >> 1;
//	}
//	return ret;
//}
//int main() {
//	int n, m, k;
//	scanf("%d %d %d",&n,&m,&k);
//	vector<long long> a(n);
//	
//	int tree_size = (1 << make_height(n));
//	vector<long long> tree(tree_size);
//	m += k;
//	for (int i=0; i<n; i++) {
//		scanf("%lld",&a[i]);
//	}
//	init(a, tree, 1, 0, n-1);
//	while (m--) {
//		int t1,t2,t3;
//		scanf("%d",&t1);
//		if (t1 == 1) {
//			int t2;
//			long long t3;
//			scanf("%d %lld",&t2,&t3);
//			t2-=1;
//			long long diff = t3-a[t2];
//			a[t2] = t3;
//			update(tree, 1, 0, n-1, t2, diff);
//		} else if (t1 == 2) {
//			int t2,t3;
//			scanf("%d %d",&t2,&t3);
//			printf("%lld\n",sum(tree, 1, 0, n-1, t2-1, t3-1));
//		}
//	}
//	return 0;
//}