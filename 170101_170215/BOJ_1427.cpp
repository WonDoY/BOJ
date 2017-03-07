#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	char string[100] = {0,};
	scanf("%s", string);
	int len = strlen(string);
	bool nonzero = true;
	sort(string,string+len);

	for(int i = len - 1 ; i >= 0; i--){
		if(nonzero){
			printf("%c",string[i]);
		}
	}
	printf("\n");
	return 0;
}