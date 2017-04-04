
/*
#include<iostream>
using namespace std;

int main()
{
	int t, num, i , cnt, n = 1;
	
	cin >> t;
	while (t--)
	{
		char str[1000] = {0,};
		cnt = 0;
		cin >> num >> str;
		for(i = 0 ; str[i] != 0 ; i++) cnt++;

		for(i = num-1 ; i < cnt ; i++)
		{
			str[i] = str[i+1];
		}
		cout << n++ << " "<< str << endl;
	}
} */