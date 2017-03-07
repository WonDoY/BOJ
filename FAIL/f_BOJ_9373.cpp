#include<cstdio>
#include<queue>
#include<functional>
#include<utility>
#include<cmath>
#define mt(a,b,c) make_tuple(a,b,c)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long double ld;

priority_queue<ld, vector<ld>, greater<ld> > Q;
vector< pair< pair<ld, ld>, ld > > circle;
int n; // the # of sensor
bool impossible = false;
ld wall[2] = {0, 0};

ld distance(ld x1, ld y1,ld r1, ld x2, ld y2, ld r2){
	ld ret = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) - (r1 + r2); 	
	return ret;
}

void condition(ld l1, ld r1, ld l2, ld r2, ld dist){
	ld p;

	if( l1 <= 0 && r1 <= 0 ) impossible = true;
	if( l2 <= 0 && r2 <= 0 ) impossible = true;

	if( dist <= 0 ){
		if( l1 <= 0
	}
	else if( dist > 0 ){

	}

}

void calc(ld x, ld y, ld r, int start){
	if(impossible) return;

	for(int i = start+1 ; i < n ; i++){
		ld x2 = circle[i].first.first;
		ld y2 = circle[i].first.second;
		ld r2 = circle[i].second;
		ld dist = distance(x, y, r, x2, y2, r2); 
		// 0 < dist 사이 거리 있음
		// dist <= 0 겹침
		ld lw1 = x - wall[0] - r;
		ld rw1 = x - wall[1] - r;
		ld lw2 = x2 - wall[0] - r2;
		ld rw2 = x2 - wall[1] - r2;

		condition(lw1, rw1, lw2, rw2, dist);
		
	}

}


int main(){
	int tc;
	for(scanf("%d", &tc) ; tc-- ; ){
		ld result = 0;
		impossible = false;
		scanf("%Lf", &wall[1]);
	
		scanf("%d", &n);
		
		
		for(int i = 0 ; i < n ; i++){
			ld x, y, r;
			scanf("%Lf %Lf %Lf", &x, &y, &r);
			circle.push_back(mp(mp(x,y),r));
			
			// left wall dist
			
			/*if(leftwall <= 0 && rightwall <= 0) impossible = true;
			else if(!impossible) {
				ld pushdata = (leftwall < rightwall)? leftwall : rightwall ;
				if(leftwall <= 0) pushdata = rightwall;
				if(Q.empty()){
					Q.push(pushdata);
				}else if(Q.top() > pushdata){
					Q.push(pushdata);
				}
			}*/
		} // input

		if(!impossible){
			for(int i = 0 ; i < n ; i++){				
				calc(circle[i].first.first , circle[i].first.second , circle[i].second , i);
			}
		}

		if(impossible){
			printf("0\n");
		}else{
			printf("%.6Lf\n", Q.top());
		}
	}
	return 0;
}