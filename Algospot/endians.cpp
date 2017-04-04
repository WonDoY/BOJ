#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>> t;
	unsigned int a;
	unsigned int ans;
	int sav;
	while(t--)
	{
		ans = 0 ;
		cin >> a ;
		
		sav = a & (0xFF000000);
		sav = sav >> 24;		
		ans = sav | ans;

		sav = a & (0x00FF0000);		
		sav = sav >> 8;
		ans = sav | ans;
		
		sav = a & (0x0000FF00);		
		sav = sav << 8;		
		ans = sav | ans;
		
		sav = a & (0x000000FF);
		sav = sav << 24;
		ans = sav | ans;
		
		cout << ans << endl;
		
	}

	return 0;
}

