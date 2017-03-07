#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 101
using namespace std;

int main(){
	char LS[MAX] = {0,};
	int N; 
	int out=0;
	scanf("%s",LS);
	for(int i = 0 ; i < strlen(LS);i++) if(LS[i] != '*') out++;
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++){
		char input[MAX] = {0,};
		int table[MAX][MAX] = {0,};
		scanf("%s",input);
		int LSLen = strlen(LS);
		int inLen = strlen(input);
		for(int li = 1 ; li <= LSLen ; li++){
			for(int ini = 1 ; ini <= inLen ; ini++ ){
				if(LS[li-1] == '*'){
					table[li][ini] = max(table[li-1][ini-1] , max(table[li-1][ini], table[li][ini-1]));
				}else{
					if(LS[li-1] == input[ini-1]){
						table[li][ini] = table[li-1][ini-1] + 1;
					}else{
						table[li][ini] = 0;
					}
				}
			}
			if(out == table[LSLen][inLen]) printf("%s\n",input);
		}

	}
	return 0;
}