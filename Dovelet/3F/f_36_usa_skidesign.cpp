// greedy 
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 1000
int a[MAX];
int main(){
	int n;
	int res=0;
	int tmp;
	int max, min, maxidx, minidx;
	scanf("%d",&n);
	for(int i=0 ; i < n;i++){
		scanf("%d",&a[i]);
	}
	while(1){
		max = 0 ; min = 100;
		for(int i = 0 ; i < n ; i++){
			if(max < a[i]){
				max = a[i];
				maxidx = i;
			}
			if(min > a[i]){
				min = a[i];
				minidx = i ;
			}
		}
		printf("before <<%d>> %d<%d> %d<%d> > %d > %.0f\n",a[maxidx]-a[minidx],maxidx,a[maxidx], minidx,a[minidx],res,ceil((max-min-17)/2.0));
		if(max-min <= 17){
			break;
		}else{
			tmp = ceil((max-min-17)/2.0); // 37 19 61 43 // 61-43-17 = 1/2 
			// 최고 값 - 최저 값 : 차이가 17이 되어야함.
			// 63 - 43 - 17 = 3 / 2 61 45 
			a[maxidx] -= tmp;
			a[minidx] += tmp;
			res += 2*tmp*tmp;
		}
		printf("after <<%d>> %d<%d> %d<%d> > %d > %.0f\n\n",a[maxidx]-a[minidx],maxidx,a[maxidx], minidx,a[minidx],res,ceil((max-min-17)/2.0));
	}

	printf("%d",res);
	return 0;
}