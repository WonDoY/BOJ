#include<iostream>
using namespace std;
#define SWAP(x, y) {char temp = x; x = y ; y = temp;}
int main()
{
	int t, i , j ,k ,cnt ,ans;
	cin >> t;
	
	while(t--)
	{
		char str[1000] = {0,};
		cnt = 0;
		cin >> str;
		for(i = 0 ; str[i] != 0 ; i++)
			cnt++;
	
		for( i = 0 ; i < cnt ; i += 2)
		{
			for( j = 0 ; j < cnt - i ; j+= 2)
			{
				k = j+2;
				if( str[j+1] > str[k+1] && str[k] != 0) 
				{				
					SWAP(str[j],str[k]);
					SWAP(str[j+1],str[k+1]);
				}
			}
		}
		for( i = 0 ; i < cnt ; i += 2)
		{
			for( j = 0 ; j < cnt - i ; j+= 2)
			{
				k = j+2;
				if( str[j] > str[k] && str[k] != 0)
				{				
					SWAP(str[j],str[k]);
					SWAP(str[j+1],str[k+1]);
				}
			}
		}

		cout << str << endl;
	}

	return 0;
}