#include<cstdio>
#include<cstring>
#define MAX 300
using namespace std;
char command[MAX];

int main(){
	while(1){
		memset(command, 0, MAX);
		gets(command);
		if(strlen(command)==1 && command[0]=='#') break;

		
	}
	return 0;
}