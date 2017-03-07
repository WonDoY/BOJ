#include<cstdio>
#include<cmath>
using namespace std;
typedef long double Lf;
bool distan(Lf a, Lf b, Lf x, Lf y, Lf r){
	Lf dist = sqrt(pow(a-x,2)+pow(b-y,2));
	return (dist < r)? true : false;
}
int main(){
	int tc;
	for(scanf("%d", &tc); tc-- ; ){
		Lf x,y,a,b;
		scanf("%Lf%Lf%Lf%Lf", &x, &y, &a, &b);
		
		int orbit;
		int result = 0;
		for(scanf("%d", &orbit); orbit--; ){
			// 하나만 포함될 때만 세어주면됨.
			Lf cx,cy,cr;
			scanf("%Lf%Lf%Lf", &cx, &cy, &cr);
			bool t1 = distan(x,y,cx,cy,cr);
			bool t2 = distan(a,b,cx,cy,cr);
			if( t1 ^ t2 ){
				result++;
			}
		}
		printf("%d\n",result);
	}
	return 0;
}