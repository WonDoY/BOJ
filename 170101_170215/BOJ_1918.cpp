// 후위연산자 
#include<cstdio>
#include<stack>
#include<cstring>
#define MAX 1000000
using namespace std;
char inString[MAX];
int main(){
	stack<char> s;
	// character inputs are +, -, *, / and (, ), [A-Z].
	scanf("%s",inString);
	int slen = strlen(inString);
	for(int idx = 0 ; idx < slen ; idx++){
		char inChar = inString[idx];
		switch(inChar){
		case '+': case '-': // 
			while(s.size() > 0){
				if(s.top() == '(' ) break;
				printf("%c", s.top()); s.pop();
			}
			s.push(inChar);
			break;
		case '*': case '/':
			while(s.size() > 0){
				if(s.top() == '(' || s.top() == '+' || s.top() == '-') break;
				printf("%c", s.top()); s.pop();
			}
			s.push(inChar);
			break;
		case '(':
			s.push(inChar);
			break;
		case ')':
			while(s.size() > 0){
				if(s.top() == '('){ s.pop(); break;}
				printf("%c", s.top()); s.pop();
			}
			break;
		default:
			printf("%c",inChar);
			break;
		}
	}
	while(s.size() > 0){
		printf("%c",s.top()); s.pop();
	}
	return 0;
}
// 18% 틀렸습니다.
// 36% 틀렸습니다.
// 18% 틀렸습니다.