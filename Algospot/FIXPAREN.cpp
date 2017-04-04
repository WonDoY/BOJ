#include<iostream>
using namespace std;

class Stack
{
public :
	char stk[100];
	int top;
	Stack()
	{
		top = -1;
	}
	void Push(char ch)
	{
		stk[++top] = ch;
	}
	char Pop()
	{
		if(top == -1 ) return 0;
		return stk[top--];
	}
};

int Len(char str[])
{
	int count = 0;
	for( int i = 0 ; str[i] != 0 ; i++)
		count++;
	return count ;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{		
		char str1[1000] = {0,};
		char str2[5] = {0,};
		char str3[5] = {0,};
		Stack *stk = new Stack();
		cin >> str1  >> str2;
		for(int i = 3 ; i >= 0 ; i--)
		{
			stk->Push(str2[i]);
		}
		for(int i = 0 ; i < 4 ; i++)
		{
			char temp = stk->Pop();
			switch(temp)
			{
			case '<': str3[i] = '>'; break;
			case '{': str3[i] = '}'; break;
			case '[': str3[i] = ']'; break;
			case '(': str3[i] = ')'; break;
			}
		}

		int len = Len(str1);
		int j ;
		int k ;
		int n1,n2;
		for(int i = 0 ; i < len ; i++)
		{
			j=0;
			k=0;
			while(str1[i] == '<' || str1[i] == '{' || str1[i] == '[' || str1[i] == '(' )
			{ // 여는 괄호를 맞는 닫는 괄호로 변경하기 위한 while
				k++;
				switch(str1[i + k])
				{ // 여는괄호일경우 이동
				case '<':case '{':case '[':case '(':
					j++; break;
				} // end switch 

				if(j == 0)
				{
					if( str1[i] == str2[0] ) n1 = 0;
					else if( str1[i] == str2[1] ) n1 = 1;
					else if( str1[i] == str2[2] ) n1 = 2;
					else if( str1[i] == str2[3] ) n1 = 3;

					if( str1[i+k] == str3[0] ) n2 = 0;
					else if( str1[i+k] == str3[1] ) n2 = 1;
					else if( str1[i+k] == str3[2] ) n2 = 2;
					else if( str1[i+k] == str3[3] ) n2 = 3;
					
					if(n1 > n2) str1[i] = str2[n2];
					else if(n1 < n2) str1[ i+k ] = str3[n1]; 
					
					break; // end while break;
				}
				else if( j != 0 )
				{
					k++;
					switch(str1[i + k])
					{ // 닫는괄호인데 아직 맞는 위치가 아닌 경우 
					case '>':case '}':case ']':case ')':						
						j--;
						break;
					} // end switch
				} // end if else				
			} // end while
		} // end for
		cout << str1  << endl;
	} // end testcase while
	return 0;
}