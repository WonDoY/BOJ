#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10000
using namespace std;
typedef long long ll;
ll a[MAX];
int main(){
	int tc, m;
	scanf("%d", &tc);
	for(int i = 0 ; i < tc ; i++){
		memset(a,0,MAX);
		scanf("%d", &m);
		printf("%d\n", (m+1)/2);
		for(int j = 0 ; j < m ; j++){
			scanf("%lld",&a[j]);
			if(j%2==0){
				sort(a,a+j+1);
				printf("%lld",a[j/2]);
				if(j!=m-1){
					if(j%18==0 && j>0) printf("\n");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}