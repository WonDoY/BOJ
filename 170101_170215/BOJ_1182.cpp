#include<cstdio>
#define MAX 20
int t,s;
int arr[MAX] = {0,};
int cnt = 0;

void search(int sum, int n, int idx, const int r){
	int SUM = sum;
	if(idx>t){
		return;
	}
	
	if(n==r){
		//printf("r : %d / sum : %d\n", r,SUM);
		if(s==SUM){
			cnt++;
		}
	}else{
		SUM += arr[idx];			
		search(SUM, n+1, idx+1, r); // 1 - - - 0
		search(sum, n, idx+1, r);
	}
	
}

void solve(){
	for(int i = 1 ; i <= t ; i++){
		//printf("%d\n",i);
		search(0, 0, 0, i);
		
	}
	printf("%d\n",cnt);
}

int main(){
	scanf("%d%d",&t,&s);
	for(int i = 0 ; i < t ; i++) scanf("%d",&arr[i]);
	
	solve();
	
	return 0;
}































//#include<cstdio>
//#define MAX 20
//int cnt = 0;
//int arr[MAX] = {0,};
//int n, s;
//// 1 2 3 
//// 1 2 
//// 1 3
//// 2 3
//// 1 
//// 2 
//// 3
//void check(int check){
//	if(check==s) cnt++;
//}
//void solve(){
//	int sum = 0;
//	int tmp = n;
//	int size = 1;
//	while(tmp--){
//		size*=2;
//	}
//	int max = size; // 5 100000 = 32
//	//printf("size : %d\n" , size );
//	for(int i = 0 ;i < max ; i++){
//		//printf("{");
//		for(int j = 0 ; j < size ; j++){
//			printf("i = %d / (1<<j) = %d // i&(1<<j) = %d\n", i, (1<<j) , i&(1<<j));
//			if(i & (1 << j) ){
//				sum+=arr[j];
//				//printf("%d ",arr[j]);
//			}
//		}
//		check(sum);
//		//printf("}\n");
//	}
//}
//int main(){
//	//printf("%d",2<<4);
//	scanf("%d%d",&n,&s);
//	for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
//
//	solve();
//	printf("%d\n",cnt);
//	return 0;
//}