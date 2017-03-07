#include<cstdio>
#include<algorithm>
#define MAX 100001
// 100000
// O(log n)
// O(5) -> 100000
// O(n log n)
// O(100000 * 5)

using namespace std;
int a[MAX] = {0,};
int b[MAX] = {0,};
int n;
bool binarySearch(int v){
	int start = 0, end = n-1;
	int mid = (start+end)/2;
	while(1){
		if(start==end){
			if(a[mid]==v){
				return true;
			}else{
				return false;
			}
		}
		if(start > end){
			return false;
		}
		if(a[mid]==v){
			return true;
		}
		else if(a[mid]<v){
			start = mid+1; // 0 4 2 4 3 4
			mid = (start+end)/2;
		}
		else if(a[mid]>v){
			end = mid-1;
			mid = (start+end)/2;
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	sort(a,a+n);

	int m; scanf("%d",&m);	
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&b[i]);
		if(binarySearch(b[i])) puts("1");
		else puts("0");
	}
	return 0;
}