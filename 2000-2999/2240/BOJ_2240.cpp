#include<cstdio>
#include<algorithm>
#define TMAX 1001
#define WMAX 31
using namespace std;

int t, w; 
int table[TMAX][WMAX] = {0,};
int input[TMAX] = {0,};
int main(){
	scanf("%d %d",&t, &w);
	for(int i = 1 ; i <= t ; i++) scanf("%d", &input[i]);
	int current = 0;
	int result = 0;
	for(int tree = 1 ; tree <= t ; tree++){
		for(int move = w ; move >= 0 ; move--){
			current = 0;
			if( ( ( input[tree] + 1 ) % 2) == ((w-move)%2) ) current = 1;
			table[tree][move] = max(table[tree-1][move], table[tree-1][move+1]) + current;
			result = max(result, table[tree][move]);
		}
	}
	printf("%d\n",result);
	return 0;
}