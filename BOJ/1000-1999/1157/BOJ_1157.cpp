#include<cstdio>
#include<cstring>
#define MAX 1000010

int dic[26] = {0,}; // 0 - 25 / 26 - 51
//abcde fghij klmno pqrst vuwxy z
//97-122 : 26
//ASCII CODE 참조.
//A 65-90 : 26
int main(){
	char* string=new char[MAX]; gets(string);
	int len = strlen(string);
	for(int i = 0 ; i < len ; i++){
		if('a' <= string[i]) dic[string[i]-'a']++;
		else if('A' <= string[i]) dic[string[i]-'A']++;
	}
	int max = 0, cnt = 0, maxidx = 0;
	for(int i = 0 ; i < 26 ; i++) if(max < dic[i]) max = dic[i];
	for(int i = 0 ; i < 26 ; i++){
		if(max==dic[i]){
			cnt++;
			maxidx=i;
		}
	}
	if(cnt>1) printf("?");
	else printf("%c", maxidx+'A');
	return 0;
}
// 아.....문제좀 잘읽자...
//1.........출력
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 <<<대문자>>>로 출력한다.
// 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

//2............
//. 단, 대문자와 소문자를 구분하지 않는다.