/**
어떤 규칙?
(1) defalut value
1 (1) 1개의 1

(1 1) 
(2) 1 2개의 1

(2 1)
1 (2 1) 1 1개의 2/ 1개의 1

1 2 (1 1) 
1 1 1 (2 2 1) / 1개의 1 / 1개의 2 / 2개의 1

1 3 2 2 1 1

*/

#include<cstdio>
void solve(){
	int a[10000] = {0,};
	int in;
	//int temp = ;
	int cnt = 0;
	while(true){
		scanf("%d",&in);
		if(!in) break;
		if(in!=temp){
			cnt += 10;
		}
		a[in+cnt]++;
		temp = in;
	}
	for(int i = 1 ; i < 10000 ; i++){
		if(a[i]){
			printf("%d %d ",a[i],i);
		}
	}
}
int main(){
	solve();
	return 0;
}