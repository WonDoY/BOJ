#include<iostream>
using namespace std;

int main()
{
	int t ;
	cin >> t;
	int N, K;
	
	while(t--)
	{
		N = 0 ; K = 0;
		int res[2] = {0,};
		int idx = 0;
		int head = 0;
		int i;
		
		cin >> N >> K;
		int con = N;
		int* arr = new int[N];

		for(int i = 0 ; i < N ; i++) arr[i] = 1;

		while(N>2) 
		{
			
			if (arr[head] == 1 )
			{
				arr[head++] = -1;
				N--;

				i = 0 ;
				while( i < K-1)
				{
					if(arr[head] == 1) i++; 
					head = (head+1) % (con); // cycle
				}
				
			}
			else if(arr[head] == -1)
			{
				head = (head+1) % (con);
			}
		}
		
		for(int i = 0 ; i < con ; i++)
		{
			if(arr[i] == 1)	res[idx++] = i + 1; 
		}
		
		cout << res[0] << " " << res[1] << endl;

		delete arr;
	}

	return 0;
}