// scc
// 7% Æ²·È½À´Ï´Ù.
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 10000
#define CMAX 200
#define mpic(a,b,c) make_pair(a,make_pair(b,c))
#define INF 0x7FFFFFFF
using namespace std;
queue<pair<int, pair<int,string> > > q;
bool visited[MAX];
int start, want;
pair<int, pair<int, string> > p;
void comp(int num,string c,char add, int cnt){
	switch(add){
	case 'S': 
		if(num < 0) num = 9999; // ¾Æ ¶Ç ¹®Á¦ »©¸Ô°íÀÐ¾ú³×
		if(!visited[num]){
			visited[num] = true;
			c += add;
			q.push(mpic(num, cnt, c));
		}
		break;
	default :
		num = num % 10000;
		if(!visited[num]){
			visited[num] = true;
			c += add;
			q.push(mpic(num, cnt, c));
		}
		break;
	}
}
void bfs(){
	while(!q.empty()){
		p = q.front();
		q.pop();		

		int regi = p.first;
		int count = p.second.first;
		string cptr(p.second.second);

		if(regi == want){
			printf("%s\n", cptr.c_str());
			return;
		}
		comp(2*regi, cptr, 'D', count+1);
		comp(regi-1, cptr, 'S', count+1);
		int dnum = regi;
		int lnum = dnum/1000;
		dnum = (dnum%1000)*10 + lnum;
		comp(dnum, cptr, 'L', count+1);
		dnum = regi;
		lnum = dnum % 10;
		dnum = (lnum *1000)+ (dnum/10);
		comp(dnum, cptr, 'R', count+1);
	}
}
void init(){
	while(!q.empty()) q.pop();
	for(int i = 0 ; i < MAX ; i++) 	visited[i] = 0;
}
int main(){
	int tc;
	for(scanf("%d",&tc) ; tc-- ; ){
		init();

		scanf("%d %d",&start ,&want);
		q.push(mpic(start,0,""));
		visited[start] = true;
		bfs();
	}
	return 0;
}



//#include<iostream>
//#include<cstdio>
//#include<queue>
//#include<algorithm>
//#include<cstring>
//#define MAX 10000
//#define CMAX 200
//#define mpic(a,b,c) make_pair(a,make_pair(b,c))
//#define INF 0x7FFFFFFF
//using namespace std;
//queue<pair<int, pair<int,string> > > q;
//int visited[MAX];
//int start, want;
//int finalCount = INF;
//pair<int, pair<int, string> > p;
//void comp(int num,string c,char add, int cnt){
//	switch(add){
//	case 'S': 
//		if(num >= 0){
//			if(visited[num] > cnt){
//				visited[num] = cnt;
//				c += add;
//				q.push(mpic(num, cnt, c));
//			}
//		}
//		break;
//	default :
//		if(num < MAX){
//			if(visited[num] > cnt){
//				visited[num] = cnt;
//				c += add;
//				q.push(mpic(num, cnt, c));
//			}
//		}// +
//		break;
//	}
//	if(want == num && finalCount > cnt){
//		finalCount = cnt;
//	}
//
//}
//void bfs(){
//	while(!q.empty()){
//		p = q.front();
//		q.pop();		
//
//		int regi = p.first;
//		int count = p.second.first;
//		string cptr(p.second.second);
//
//		if(regi == want && count == finalCount){
//			printf("%s\n", cptr.c_str());
//			return;
//		}
//		comp(2*regi, cptr, 'D', count+1);
//		comp(regi-1, cptr, 'S', count+1);
//		int dnum = regi;
//		int lnum = dnum/1000;
//		dnum = (dnum%1000)*10 + lnum;
//		comp(dnum, cptr, 'L', count+1);
//		dnum = regi;
//		lnum = dnum % 10;
//		dnum = (lnum *1000)+ (dnum/10);
//		comp(dnum, cptr, 'R', count+1);
//	}
//}
//void init(){
//	while(!q.empty()) q.pop();
//	finalCount = INF;
//	for(int i = 0 ; i < MAX ; i++) 	visited[i] = 10000;
//}
//int main(){
//	int tc;
//	for(scanf("%d",&tc) ; tc-- ; ){
//		init();
//
//		scanf("%d%d",&start ,&want);
//		q.push(mpic(start,0,""));
//		visited[start] = 1;
//		bfs();
//	}
//	return 0;
//}