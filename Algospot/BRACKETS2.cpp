#include<iostream>
using namespace std;

class Stack
{
private :
	char stk[10000];
	int top;
public :
	Stack()
	{
		for(int i = 0 ;i < 10000 ; i++)
			stk[i] = 0;
		top = -1;
	}
	
	char Pop()
	{
		if( isEmpty() ) return 0;
		else return stk[top--];
	}
	bool isEmpty()
	{
		if( top == -1 ) return true;
		return false;
	}
	void Push(char ch)
	{
		stk[++top] = ch;
	}
};

int main()
{
	int t;
	cin >> t ;
	
	while(t--)
	{
		Stack *stk = new Stack();
		char str[10000] = {0,};
		int cnt = 0 ;
		bool ans = true;

		cin >> str;

		for(int i = 0 ; str[i] != 0 ; i++) cnt++;

		for(int i = 0 ; i < cnt && (ans == true) ; i++ )
		{
			switch(str[i])
			{
			case '(':
				stk->Push('('); break;
			case '{':
				stk->Push('{'); break;
			case '[':
				stk->Push('['); break;
			case ']':
				if( stk->Pop() != '[' ) ans = false;
				break;
			case '}':
				if( stk->Pop() != '{' ) ans = false;
				break;
			case ')':
				if( stk->Pop() != '(' ) ans = false;
				break;
			}
		}
		if(!stk->isEmpty() ) ans = false; 
		delete stk;

		if( ans ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
