// vs 10 버전 이하는 돌아가지 않음. 왜냐면 없음 map을 저렇게 사용하는게, vs 10버전 위로 올라와서 코딩함.
#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#define MAX 303030
#define SMAX 21
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

vector<int> parent;
int res[MAX];
map<string, int> m;

int find(int u) {
	if (u == parent[u]) return u;
	return find(parent[u]);
} // u가 속한 루트 반환

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;
	parent[u] = v;
} // u가 속한트리와 v가 속한 트리 합침

void init(int n) {
	parent.resize(n);
	for (int i = 0; i < n; i++) parent[i] = i, res[i] = 1;
} // 각자의 부모를 할당 시킴.

int main() {
	int tc;
	for (scanf("%d", &tc); tc--; ) {
		char n1[SMAX], n2[SMAX];
		int F;
		int passign = 1;
		m.clear();
		parent.clear();
		scanf("%d", &F);
		init(3*F);
		for (int i = 0; i < F; i++) {
			scanf("%s %s", &n1, &n2);

			if (m.count(n1) == 0) m.insert(mp(n1, passign++));
			if (m.count(n2) == 0) m.insert(mp(n2, passign++));
			

			int parentNum1 = find(m[n1]);
			int parentNum2 = find(m[n2]);


			if (parentNum1 == parentNum2) {
				printf("%d\n", res[parentNum1]);
			}
			else {
				merge(parentNum1, parentNum2);
				res[parentNum2] += res[parentNum1];
				printf("%d\n", res[parentNum2]);
			}
		}		
	}
	return 0;
}

//#include<cstdio>
//#include<vector>
//#include<list>
//#include<cstring>
//#include<set>
//#include<map>
//#define MAX 101010
//#define SMAX 21
//#define pb(a) push_back(a)
//using namespace std;
//
////char name[MAX][SMAX];
//map<string, int> m;
//int parent[MAX];
//
//typedef struct disjointset{
//	int count;
//	list<int> child;
//}DJS;
//
//DJS s[MAX];
//
//void union_set(int dnum, int ddnum){
//	s[dnum].count += s[ddnum].count;
//	s[ddnum].count = 0;
//	for(auto iter = s[ddnum].child.begin() ; iter != s[ddnum].child.end() ; iter++){
//		int node = *iter;
//		s[dnum].child.pb(node);
//		parent[node] = dnum;
//	}
//	s[ddnum].child.clear();
//}
//
//int main(){
//	int tc;
//	for(scanf("%d", &tc) ; tc-- ; ){
//		int F;
//		int pnum = 1;
//		int djsnum = 1;
//		
//		//memset(parent, 0x00, MAX);
//		scanf("%d", &F);
//		while(F--){
//			//memset(tmp1, 0, 21);
//			//memset(tmp2, 0, 21);
//			char tmp1[21];
//			char tmp2[21];
//			scanf("%s %s",tmp1, tmp2);
//						
//			int exist1 = -1;
//			int exist2 = -1;
//
//			for(int i = 0 ; i < pnum ; i++){
//				if( m.count(tmp1) > 0 ) exist1 = m.count(tmp1);
//				if( m.count(tmp2) > 0 ) exist2 = m.count(tmp2);
//			}
//
//			int res = 0;
//			if(exist1 == -1 && exist2 == -1){ // 없다 추가해야한다. 
//				m[tmp1] = pnum;
//				m[tmp2] = pnum+1;
//				parent[pnum] = djsnum;
//				parent[pnum+1] = djsnum;
//				s[djsnum].count += 2;
//				s[djsnum].child.pb(pnum);
//				s[djsnum].child.pb(pnum+1);
//				pnum += 2;
//				
//				res = s[djsnum++].count;
//			}else if(exist1 == -1){ // exist2 는 있다.
//				m[tmp1] = pnum;				
//				parent[pnum] = parent[exist2];
//				s[parent[exist2]].count += 1;
//				s[parent[exist2]].child.pb(pnum);
//				pnum += 1;
//				res = s[parent[exist2]].count;
//			}else if(exist2 == -1){ // exist1 은 있다.
//				m[tmp2] = pnum;
//				parent[pnum] = parent[exist1];
//				s[parent[exist1]].count += 1;
//				s[parent[exist1]].child.pb(pnum);
//				pnum += 1;
//				res = s[parent[exist1]].count;
//			}else{ // 둘 다 있다. 	
//				if(parent[exist1] != parent[exist2]){
//					union_set(parent[exist1], parent[exist2]);
//				} 
//				res = s[parent[exist1]].count;
//			}
//			printf("%d\n",res);
//		}
//		for(int i = 0 ; i <= djsnum ; i++){
//			s[i].count = 0;
//			s[i].child.clear();
//		}
//		m.clear();
//	}
//	return 0;
//}
//// 20% TLE
//// 20% TLE
//// 20% RTE
//// 20% RTE
//// 20% TLE