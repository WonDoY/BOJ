// 5582
// 공통 부분 문자열 CS
// string s > t , t에 s가 연속
// 길이 [1,4000]
// 
// input 
// 문자열 A 
// 문자열 B 
// output
// 두문자열에 모두 포함된 부분 문자열 중 가장 긴 것의 길이를 출력한다.

//a: ABRACADABRA
//b: ECADADABRBCRDARA
//4000, 4000 이라고 하면... 
// strcmp 을 써서 == 0 이라면.. ? 
//그럼 시간초과 뜰 것 같은데 
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 4002
using namespace std;
char a[MAX] = {0,};
char b[MAX] = {0,};
int table[MAX][MAX] = {0,};
int result = 0;
int cnt = 0;
void printTable(int alen, int blen){
	for(int ai = 1 ; ai <= alen ; ai++){
		for(int bi = 1 ; bi <= blen ; bi++){
			printf("%2d",table[ai][bi]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%s", a);
	scanf("%s", b);
	int alen = strlen(a);
	int blen = strlen(b);
	for(int ai = 1 ; ai <= alen ; ai++){
		for(int bi = 1 ; bi <= blen ; bi++){
			cnt = 0;
			if(a[ai-1]==b[bi-1]) cnt=1;
			if(cnt==1){
				table[ai][bi] = cnt + table[ai-1][bi-1];
			}
			result = max(result, table[ai][bi]);
		}
	}
	//printTable(alen,blen);
	printf("%d",result);
	return 0;
}