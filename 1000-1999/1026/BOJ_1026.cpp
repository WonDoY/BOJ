#include<cstdio>
#include<algorithm>
#include<functional>
#define MAX 100
using namespace std;
int a[MAX] = {0,};
int b[MAX] = {0,};
int main(){
	int n = 0; scanf("%d",&n);
	for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	for(int i = 0 ; i < n ; i++) scanf("%d",&b[i]);
	sort(a,a+n,greater<int>());
	sort(b,b+n);
	int sum = 0;
	for(int i = 0 ; i < n ; i++) sum+=a[i]*b[i];
	printf("%d\n",sum);
	return 0;
}
//5
//1 1 1 6 0
//2 7 8 3 1