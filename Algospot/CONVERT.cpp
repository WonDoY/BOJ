#include<iostream>
using namespace std;

int main()
{
	int t, n = 1 , s;
	float num;
	
	cin >> t;
	while(t--)
	{
		
		char str[3] = {0,};
		char* unit;
		cin >> num >> str;

		if(str[0] == 'k')
		{
			num *= 2.2046 ; unit = "lb";
		}
		else if( str[0] == 'l')
		{
			if( str[1] == 'b'){
				num *=0.4536 ; unit = "kg"; 
			}
			else{
				num *= 0.2642; unit = "g";
			}
		}
		else if( str[0] == 'g')
		{
			num *= 3.7854 ; unit = "l";
		}
		printf("%d %.4f %s\n",n++, num, unit);

	}
	
}