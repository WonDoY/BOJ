#include<cstdio>
#include<vector>
#define vll vector<ll>
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int make_height(int cnt);
int min2(int a, int b){
	return (a>b)?b:a;
}
int max2(int a, int b){
	return (a>b)?a:b;
}
ll init(vll& a, vll& tree, int node, int start, int end);
ll sum(vll& tree, int node, int node_s, int node_e, int left, int right);
void update(vll& tree, int node, int node_s, int node_e, int index, ll diff);

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vll v(n);
	vll tree(1 << make_height(n));
	ll in = 0;
	for(int i = 0 ; i < n ; i++) scanf("%lld", &v[i]);

	int command;
	init(v, tree, 1, 0, n-1);
	for(int i = 0 ; i < q ; i++){
		//scanf("%d %d %d", &command, &a, &b);
		int a, b;
		scanf("%d %d",&a, &b);

		printf("%lld\n", sum(tree, 1, 0, n-1, min2(a-1, b-1), max2(a-1, b-1)) );
		int c;
		ll d;
		scanf("%d %lld", &c, &d);
		ll diff = d - v[--c];
		v[c] = d;
		update(tree, 1, 0, n-1, c, diff);
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