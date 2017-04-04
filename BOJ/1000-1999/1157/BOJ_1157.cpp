#include<cstdio>
#include<cstring>
#define MAX 1000010

int dic[26] = {0,}; // 0 - 25 / 26 - 51
//abcde fghij klmno pqrst vuwxy z
//97-122 : 26
//ASCII CODE ����.
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
// ��.....������ ������...
//1.........���
// ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� <<<�빮��>>>�� ����Ѵ�.
// ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.

//2............
//. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.