#include<iostream>
using namespace std;

int main()
{
	int count = 0 ;
	int i, j;
	cin >> count;

	if( count < 1 || count > 50 ) return 0;
	char** str = new char*[count];
	for( i = 0 ; i < count ; i++)
	{
		str[i] = new char[51];
		for( j = 0 ; j < count ; j++)
		{
			str[i][j] = 0;
		}
	}

	for( i = 0 ; i < count ; i++)
	{
		cin >> str[i];
	}
	for( i = 0 ; i < count ; i++)
	{
		printf("Hello, %s!\n",str[i]);
	}
}