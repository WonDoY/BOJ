#include<cstdio>
#define MAX 1001
//2*n
//2*1(1) / 2*2(2)
// 1 : (1) 1 = 1

// 2 : (1) 2 = 2
//     (2) 1 = 1 // 3
//     

// 3 : 5 
// 2자리, 1자리

// 4 : 2(2) 3(1)

// 5 : 3(2) 4(1)

// 6 :

// 7 :

// {0,1,3,4,7,11,
//    18,2}

int res[MAX] = {0,1,3,0};
int n;
int main(){
	scanf("%d",&n);
	for(int i = 3 ; i < MAX ; i++) res[i] = (res[i-1] + 2*res[i-2])%10007;
	printf("%d",res[n]);
	return 0;
}