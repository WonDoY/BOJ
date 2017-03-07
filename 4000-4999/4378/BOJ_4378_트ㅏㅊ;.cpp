#include<cstdio>
#include<cstring>
// 대문자, 공백, 숫자, 문장부호
char convert(char a){
	switch(a){
	case 'Q': return ' ';// unuse
	case 'A': return ' ';// unuse
	case 'Z': return ' ';// unuse
	case 'W': return 'Q';
	case 'E': return 'W';
	case 'R': return 'E';
	case 'T': return 'R';
	case 'Y': return 'T';
	case 'U': return 'Y';
	case 'I': return 'U';
	case 'O': return 'I';
	case 'P': return 'O';
	case '[': return 'P';
	case ']': return '[';
	case '\\': return ']';
	case 'S': return 'A';
	case 'D': return 'S';
	case 'F': return 'D';
	case 'G': return 'F';
	case 'H': return 'G';
	case 'J': return 'H';
	case 'K': return 'J';
	case 'L': return 'K';
	case ';': return 'L';
	case '\'': return ';';
	case 'X': return 'Z';
	case 'C': return 'X';
	case 'V': return 'C';
	case 'B': return 'V';
	case 'N': return 'B';
	case 'M': return 'N';
	case ',': return 'M';
	case '.': return ',';
	case '/': return '.';
	case '1': return '`';
	case '2': return '1';
	case '3': return '2';
	case '4': return '3';
	case '5': return '4';
	case '6': return '5';
	case '7': return '6';
	case '8': return '7';
	case '9': return '8';
	case '0': return '9';
	case '-': return '0';
	case '=': return '-';
	case ' ': return ' ';
	}
	return '\n';
}
int main(){
	char str[10000];
	memset(str, 0x00, sizeof(str));
	while(1){
		gets(str);
		if(str[0] == 0) break;
		for(int i = 0 ; str[i] != NULL ; i++){
			str[i] = convert(str[i]);
		}
		puts(str);
		memset(str, 0x00, sizeof(str));
	}
	return 0;
}

// acmicpc.net
// sv,ov[v/mry