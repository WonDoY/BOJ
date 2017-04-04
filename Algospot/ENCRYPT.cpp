#include<iostream>
using namespace std;

int main()
{
	int t , i , cnt , idx;
	bool ans = false;
	cin >> t;
	char temp;
	while(t--)
	{
		char str[100] = {0,};
		char tmp[100] = {0,};
		cnt = 0;
		idx = 0;
		cin >> str;
		for(i = 0 ; str[i] != 0 ; i++) cnt++;

		for(i = 0 ; i < cnt ; i += 2)
			tmp[idx++] = str[i];

		for(i = 1 ; i < cnt ; i+=2)
			tmp[idx++] = str[i];
		
		cout << tmp << endl;
	}
	return 0;
}