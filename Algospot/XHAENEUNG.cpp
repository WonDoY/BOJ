#include<iostream>
using namespace std;

int main()
{
	int t;
	int ans;
	cin >> t ;

	char define[11][6] = {"zero", "one", "two", "three", "four", "five"
		, "six", "seven", "eight", "nine", "ten" };
	//zero, one, two, three, four, five, six, seven, eight, nine, ten 
	while( t-- )
	{
		
		char str1[6] = {0,};
		int s1 = 0, s2 = 0;
		char op1, op2;
		char str2[6] = {0,};
		char str3[6] = {0,};
		int res = 0;
		cin >> str1 >> op1 >> str2 >> op2 >> str3 ;
		int i, j;

		for( i = 0, ans = 0 ; i<11 ; i++)
		{
			for( j = 0 ; define[i][j] != 0 ; j++)
			{
				if ( define[i][j] == str1[j] ) ans++;
			}
			if( ans > 2 ){ s1 = i; break; }
		}
		
		for( i = 0, ans = 0 ; i<11 ; i++)
		{
			for( j = 0 ; define[i][j] != 0 ; j++)
			{
				if ( define[i][j] == str1[j] ) ans++;
			}
			if( ans > 2 ){ s2 = i; break; }
		}
		switch(op1)
		{
		case '+':
			res = s1 + s2;
			break;
		case '-':
			res = s1 - s2;
			break;
		case '*':
			res = s1 * s2;
			break;
		}
		
		for( i = 0 ; 


	}
	return 0;
}