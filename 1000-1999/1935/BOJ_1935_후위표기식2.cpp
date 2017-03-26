#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<utility> // pair
using namespace std;

typedef long double Lf;
const int MAX = 10000;
map<char, Lf> M;

Lf operation(char op, Lf a, Lf b){
	switch(op){
	case '+': return a+b;
	case '-': return a-b;
	case '/': return a/b;
	case '*': return a*b;
	}
	return 0;
}

int main(){
	int n; 
	char e[MAX];
	scanf("%d", &n);
	scanf("%s", e);
	for(int i = 0; i < n ; i++){
		Lf val;
		scanf("%Lf", &val);
		M.insert(make_pair('A'+i, val));
	}

	stack<Lf> S;
	for(int i = 0 ; e[i] != NULL ; i++){
		if('A' <= e[i] && e[i] <= 'Z'){
			S.push(M[e[i]]); 
		}else{
			Lf val = S.top(); S.pop();
			val = operation(e[i],S.top(),val);
			S.pop();
			S.push(val);
		}
	}

	printf("%.2Lf",S.top());
	
	return 0;
}