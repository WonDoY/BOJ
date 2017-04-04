#include<cstdio>
#include<algorithm>
#define pii pair<int, int>
#define MAX 100000
using namespace std;
pii info[MAX];
pii dist[MAX];
bool comp(const pii& a, const pii& b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main(){
	int n; scanf("%d",&n);
	int v1,v2;
	for(int i = 0 ; i < n ; i++){
		scanf("%d %d",&v1,&v2);
		info[i].first = min(v1,v2);
		info[i].second = abs(info[i].first-max(v1,v2));
	}
	int d;
	int dcnt = 0;
	scanf("%d",&d);
	for(int i = 0 ; i < n ; i++){
		int temp = info[i].second;
		if(temp <= d){
			dist[dcnt].first = info[i].first;
			dist[dcnt++].second = info[i].second;
		}
	}
	int Lflag = 0;
	int Rflag = 0;
	int result = 0;
	int count = 0;
	int xpos = dist[Lflag].first;
	sort(dist,dist+dcnt, comp);
	//for(int i = 0 ; i < dcnt ; i++){
	//	printf("%d %d\n",dist[i].first, dist[i].second);
	//}
	while(Lflag < dcnt){
		if(Rflag >= dcnt) break;
		xpos = dist[Lflag].first;
		while(1){			
			int temp = dist[Rflag].first - xpos + dist[Rflag].second;
			if(temp <= d){
				Rflag++;
				count++;
				//for(int i = Lflag ; i < Rflag ; i++){
				//	printf("%d %d\n",dist[i].first, dist[i].second);
				//}
				//printf("\n\n");
				result = max(result, count);
				if(Rflag == dcnt) break;
			}else if(temp > d){
				Rflag--;
				count--;
				break;
			}
		}


		while(1){
			if(Lflag==dcnt) break;
			if(xpos < dist[Lflag].first){
				xpos = dist[Lflag].first;
				break;
			}else{
				Lflag++;
				count--;
			}
		}
	}
	printf("%d",result);
	return 0;
}