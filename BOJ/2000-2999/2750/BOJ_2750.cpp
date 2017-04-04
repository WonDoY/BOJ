#include<cstdio>
#include<algorithm>
#define MAX 1000002
int arr[MAX] = {0,};
int main(){
	int n; scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)scanf("%d",&arr[i]);
	std::sort(arr,arr+n);
	for(int i = 0 ; i < n ; i++)printf("%d\n",arr[i]);
	return 0;
}