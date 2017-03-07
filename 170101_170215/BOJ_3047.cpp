#include<cstdio>
#include<algorithm>

int main(){
	int input[3];
	char ch[4];

	for(int i = 0 ; i < 3 ; i++) scanf("%d",&input[i]);
	scanf("%s",ch); std::sort(input, input+3);
	for(int i = 0 ; i < 3 ; i++) printf("%d ",input[ch[i]-'A']);
	return 0;
}