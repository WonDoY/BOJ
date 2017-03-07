// 좀 더 생각해보자
#include<cstdio>
#include<algorithm>
#define MAX 300000
using namespace std;
pair<int, int> xh[MAX];
// N
// L H R

int main(){
	int N;
	scanf("%d", &N);
	int count = 0;
	for(int i = 0 ; i < N ; i++){
		int L, H, R;
		scanf("%d %d %d", &L, &H, &R);
		xh[count].first = L;
		xh[count++].second = H;

		xh[count].first = R;
		xh[count++].second = H;
	}
	sort(xh, xh+count);
	for(int i = 0 ; i < count ; i++)
		printf("xpos : %d / height : %d\n", xh[i].first, xh[i].second);
	return 0;
}