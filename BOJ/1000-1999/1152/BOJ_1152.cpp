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
// ���� ���� �ϳ��� �ƴ� �� �ִٴ� ���� �����Ѵ�.
//      abcd             efghi                               jklm   
// 3 
// �հ� �ڿ��� ������ �� �� �ִ� ��츦 �����Ѵ�.