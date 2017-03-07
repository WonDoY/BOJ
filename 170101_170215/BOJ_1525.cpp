// 아 이렇게 짜면 안될거같은데.................
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
typedef struct bo{
	int count;
	int board;
}B;
queue<B> q;
set<int> s;
bool isTrueBoard(int board){
	switch(board){
	case  23456789: return true;
	case 103456789: return true;
	case 120456789: return true;
	case 123056789: return true;
	case 123406789: return true;
	case 123450789: return true;
	case 123456089: return true;
	case 123456709: return true;
	case 123456780: return true;
	}
	return false;
}
int ZeroLocation(int board){
	for(int i = 0 ; i < 9 ; i++){
		int temp = board%10;
		if(temp == 0) return 8-i; // 0 1 2 3 4 5 6 7 8
		board /= 10;
	}
	return -1;
}
int swap(int board, int zeroloc, int swaploc){
	int temp = board;
	int sloc = 1;
	int zloc = 1;
	switch(swaploc){
	case 0: 
		sloc = (temp/100000000)%10;
		temp = temp - (temp/100000000)%10 * 100000000; break;
	case 1: 
		sloc = (temp/10000000 )%10;
		temp = temp - (temp/10000000 )%10 * 10000000 ; break;
	case 2: 
		sloc = (temp/1000000  )%10;
		temp = temp - (temp/1000000  )%10 * 1000000  ; break;
	case 3: 
		sloc = (temp/100000   )%10;
		temp = temp - (temp/100000   )%10 * 100000   ; break;
	case 4: 
		sloc = (temp/10000    )%10;
		temp = temp - (temp/10000    )%10 * 10000    ; break;
	case 5: 
		sloc = (temp/1000     )%10;
		temp = temp - (temp/1000     )%10 * 1000     ; break;
	case 6: 
		sloc = (temp/100      )%10;
		temp = temp - (temp/100      )%10 * 100      ; break;
	case 7: 
		sloc = (temp/10       )%10;
		temp = temp - (temp/10       )%10 * 10       ; break;
	case 8: 
		sloc = (temp/1        )%10;
		temp = temp - (temp/1        )%10 * 1        ; break;
	}
	switch(zeroloc){
	case 0: temp = temp + sloc*100000000; break;
	case 1: temp = temp + sloc*10000000 ; break;
	case 2: temp = temp + sloc*1000000  ; break;
	case 3: temp = temp + sloc*100000   ; break;
	case 4: temp = temp + sloc*10000    ; break;
	case 5: temp = temp + sloc*1000     ; break;
	case 6: temp = temp + sloc*100      ; break;
	case 7: temp = temp + sloc*10       ; break;
	case 8: temp = temp + sloc*1        ; break;
	}
	return temp;
}
void qinsert(B temp){
	pair<set<int>::iterator, bool> sett;
	sett = s.insert(temp.board);
	if(sett.second){
		q.push(temp);
	}
}
int main(){
	int input = 0;
	int temp = 0;
	for(int i = 0 ; i < 9 ; i++){
		scanf("%d", &temp);
		input *= 10;
		input += temp;
	} // input data 000,000,000

	B firstBoard; 
	firstBoard.count = 0;
	firstBoard.board = input;
	q.push(firstBoard);
	s.insert(input);
	pair<int, bool> sett;
	while(!q.empty()){
		B b = q.front();
		q.pop();

		int current_count = b.count;
		int current_board = b.board;
		if( isTrueBoard(current_board) ){
			printf("%d\n",current_count);
			return 0;
		}
		else{
			int zeroLoc = ZeroLocation(current_board);
			int next_count = current_count + 1;
			B temp;
			temp.board = current_board;
			temp.count = next_count;
			switch(zeroLoc){
			case 0:
				temp.board = swap(current_board,0,1);
				qinsert(temp);
				temp.board = swap(current_board,0,3);
				qinsert(temp);
				break;
			case 1:
				temp.board = swap(current_board,1,0);
				qinsert(temp);
				temp.board = swap(current_board,1,2);
				qinsert(temp);
				temp.board = swap(current_board,1,4);
				qinsert(temp);
				break;
			case 2:
				temp.board = swap(current_board,2,1);
				qinsert(temp);
				temp.board = swap(current_board,2,5);
				qinsert(temp);
				break;
			case 3:
				temp.board = swap(current_board,3,0);
				qinsert(temp);
				temp.board = swap(current_board,3,4);
				qinsert(temp);
				temp.board = swap(current_board,3,6);
				qinsert(temp);
				break;
			case 4:
				temp.board = swap(current_board,4,1);
				qinsert(temp);
				temp.board = swap(current_board,4,3);
				qinsert(temp);
				temp.board = swap(current_board,4,5);
				qinsert(temp);
				temp.board = swap(current_board,4,7);
				qinsert(temp);
				break;
			case 5:
				temp.board = swap(current_board,5,2);
				qinsert(temp);
				temp.board = swap(current_board,5,4);
				qinsert(temp);
				temp.board = swap(current_board,5,8);
				qinsert(temp);
				break;
			case 6:
				temp.board = swap(current_board,6,3);
				qinsert(temp);
				temp.board = swap(current_board,6,7);
				qinsert(temp);
				break;
			case 7:
				temp.board = swap(current_board,7,4);
				qinsert(temp);
				temp.board = swap(current_board,7,6);
				qinsert(temp);
				temp.board = swap(current_board,7,8);
				qinsert(temp);
				break;
			case 8:
				temp.board = swap(current_board,8,5);
				qinsert(temp);
				temp.board = swap(current_board,8,7);
				qinsert(temp);
				break;
			}
		}
	}
	printf("-1\n");
	return 0;
}




//#include <bits/stdc++.h>
//#define REP(i,a,b) for(int i=a;i<=b;++i)
//#define FOR(i,n) for(int i=0;i<n;++i)
//#define pb push_back
//#define all(v) (v).begin(),(v).end()
//#define sz(v) ((int)(v).size())
//#define inp1(a) scanf("%d",&a)
//#define inp2(a,b) scanf("%d%d",&a,&b)
//#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
//using namespace std;
//typedef long long ll;
//typedef pair<ll,ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int,int> pii;
//typedef vector<pii> vii;
//typedef vector<pll> vll;
//typedef vector<vector<int> > vvi;
//typedef pair<int,pair<int,int> > piii;
//const double EPSILON = 1e-9;
//const double PI = acos(0.0)*2;
//const int MOD = 1000000007;
//const int INF = 0x3c3c3c3c;
//const long long INFL = 0x3c3c3c3c3c3c3c3c;
//const int MAX_N = 102;
//
//int dy[]={-1,0,0,1};
//int dx[]={0,1,-1,0};
//map<long long, int> mp;
//queue<long long> q;
//int arr[3][3];
//int ans,u;
//bool inRange(int i, int j){
//	return 0 <= i && i < 3 && 0 <= j && j < 3;
//}
//int main() {
//	long long start=0;
//	for(int i = 0; i < 9; i++){
//		scanf("%d",&u);
//		start=start*10+u;
//	}
//	q.push(start);
//	mp[start]=1;
//	bool found=false;
//	while(!q.empty()){
//		long long cur = q.front();
//		int zeroI=0,zeroJ=0;
//		q.pop();
//		bool imposs=false;
//		long long u=cur;
//		for(int i = 0; i < 9; i++,u/=10){
//			if(u%10==0) zeroI=(8-i)/3,zeroJ=(8-i)%3;
//			if(i && u%10 != 9-i) imposs=true;
//		}
//		if(!imposs) {
//			found=true;
//			ans=mp[cur]-1;
//			break;
//		}
//		for(int i = 0; i < 4; i++){
//			int newI=zeroI+dy[i],newJ=zeroJ+dx[i];
//			if(!inRange(newI,newJ)) continue;
//			long long next = cur;
//			for(int i = 0; i < 9; i++,next/=10) arr[(8-i)/3][(8-i)%3] = next%10;
//			swap(arr[zeroI][zeroJ],arr[newI][newJ]);
//			next=0;
//			for(int i = 0; i < 9; i++) next=next*10+arr[i/3][i%3];
//			if(!mp[next]) {
//				q.push(next);
//				mp[next]=mp[cur]+1;
//			}
//		}
//	}
//	if(!found) ans=-1;
//	printf("%d",ans);
//	return 0;
//}
