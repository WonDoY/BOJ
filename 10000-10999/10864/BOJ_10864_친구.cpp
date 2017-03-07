#include<cstdio>
int imap[1111];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		imap[a]++;
		imap[b]++;
	}

	for(int i = 1 ; i <= n ; i++) printf("%d\n",imap[i]);
	return 0;
}