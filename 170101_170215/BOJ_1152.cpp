#include<cstdio>
#include<cstring>
#define MAX 1000001

int main(){
	char string[MAX] = {0,};gets(string);
	int cnt = 1;
	//printf("%d\n",strlen(string));
	for(int i = 0 ; string[i] != 0 ; i++){
		if(string[i] == ' ' && string[i+1] != ' ') cnt++;
	}
	if(string[0] == ' ') cnt--;
	if(string[strlen(string)-1]==' ')cnt--; 
	printf("%d\n",cnt);
	return 0;
}
//abcd             efghi                               jklm
// 3 
// 공백 수가 하나가 아닐 수 있다는 것을 생각한다.
//      abcd             efghi                               jklm   
// 3 
// 앞과 뒤에도 공백이 들어갈 수 있는 경우를 생각한다.