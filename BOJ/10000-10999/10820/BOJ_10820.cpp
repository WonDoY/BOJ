#include<cstdio>
#include<cstring>

int main(){
	char sentence[200] = {0,};
	int lower, upper, num, space;
	while(gets(sentence)){		
		int slen = strlen(sentence);
		lower = upper = num = space = 0;
		for(int i = 0 ; i < slen ; i++){
			if('A' <= sentence[i] && sentence[i] <= 'Z') upper++;
			if('a' <= sentence[i] && sentence[i] <= 'z') lower++;
			if('0' <= sentence[i] && sentence[i] <= '9') num++;
			if(sentence[i] == ' ') space++;
		}
		printf("%d %d %d %d\n", lower, upper, num, space);
		memset(sentence, 0, 200);
	}
	return 0;
}