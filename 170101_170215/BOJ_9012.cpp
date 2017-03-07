#include<cstdio>
#include<stack>
#include<cstring>

int main(){
	int n ;
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		std::stack<char> s;
		char command[60] = {0,};
		scanf("%s", command);
		int clen = strlen(command);
		bool isYes = true;
		for(int z = 0 ; z < clen ; z++){
			if(command[z] == '(') s.push('(');
			else if(command[z] == ')') {
				if(s.empty()){
					isYes = false;
					break;
				}else{
					s.pop();
				}
			}
		}
		if(!s.empty()){
			isYes = false;
		}
		printf("%s\n",(isYes)?"YES":"NO");
	}
}