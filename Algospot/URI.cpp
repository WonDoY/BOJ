#include<iostream>
using namespace std;

int main()
{
	int t, cnt, idx ;
	cin >> t;
	while(t--)
	{
		char str[80] = {0,};
		char tmp[80] = {0,};
		cnt = 0 ; idx = 0;
		cin >> str;

		for(int i = 0 ; str[i] != 0 ; i++) {
			if(str[i] == '%') 
			{
				i++;
				if(str[i] == '2')
				{
					i++;
					if(str[i] == '0') tmp[idx++] = ' ';
					else if(str[i] == '1')tmp[idx++] = '!';
					else if(str[i] == '4')tmp[idx++] = '$';
					else if(str[i] == '5')tmp[idx++] = '%';
					else if(str[i] == '8')tmp[idx++] = '(';
					else if(str[i] == '9')tmp[idx++] = ')';
					else if(str[i] == 'a')tmp[idx++] = '*';
				}
			}
			else tmp[idx++] = str[i];
		}
		cout << tmp << endl;



	}
}