#include<cstdio>
#include<algorithm>
#define MAX 1000
using namespace std; 
int N;
int width;
int input[MAX];
int note[MAX][MAX];
pair<int,int> dp[MAX];
// 1. 이름의 길이를 넣는다. 
// 2. 길이 당 +1(공백)을 띤 이름
// 3. 이때 각 줄의 남는 공백을
// 4. 이름은 순서대로 넣어야함.
// 마지막 줄은 생각하지 않음

// tc를 나눈다. 
// Full 한 줄에 꽉채우는 경우. 
// Not Full 한 줄에 꽉채우지 않는 경우.
// 총 경우의 수가 
// 1. Full - Not Full
// 2. Full - Full
// 3. NF - F
// 4. NF - NF
// 이전에 채웠다면, 다음 것의 최적을 결정하는 데 도움이 된다.
// 다채웠을 경우의 테이블과
// 다채우지 않았을 경우 테이블이 필요하다.

// pair<int,int>
//  first = (Full)    
// second = (NotFull) 

// F F F
// F N F
// F N N 
// F F N
// 그런데 마지막 경우는 생각하지 않음.
// 2경우로 가장 잘게 쪼개서 보면

// F F / (F/N)
// F N / (F/N)
// N F / (F/N)
// N N / (F/N)....
// 이 중 가장 최소를 본다. 
// input[x...y] + (y-x (간격은 인자의 갯수 - 1 이므로)) <= width
// 채우는 경우 채우지 않는 경우.
void initTable(){
	for(int i = 0 ; i <= width ; i++){
		dp[i].first = dp[i].second = 0;
	}
}
int main(){
	scanf("%d %d",&N, &width);
	for(int i = 0 ; i < width ; i++) scanf("%d",&input[i]);

	return 0;
}