//1009
#include<cstdio>
#pragma warning(disable:4996)
int main() {
	int t, a, b, res;
	res = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		res = 1;
		while (b--) {
			res = res * a;			
			res = res % 10;			
		}
		if(res==0) printf("%d\n", 10);
		else printf("%d\n", res);
	}
	return 0;
}