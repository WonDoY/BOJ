#include<iostream>
#include<cstdio>
using namespace std;

void SWAP(int A[], int i, int j)
{
	int temp = A[i]; A[i] = A[j]; A[j] = temp;
}


int abs(int num)
{
	if(num >= 0 )return num;
	return -num;
}

void heapSort_insert( int A[] , int current, int Size)
{
	int parent, left, right;
	if( ((Size - 1) == current) &&  ( (current % 2) == 1) )
	{
		if(current >= 1)
		{
			parent = current/2;
			left = current;
			if(A [parent] < A[left] ) SWAP(A, parent, left);
			heapSort_insert(A, parent, Size);
		}
		else return ;
		
	}
	else if( current%2 == 0 && current > 0)
	{
		parent = (current-1) / 2 ;
		left = 2 * parent + 1 ;
		right = 2 * parent + 2;
		if(A [parent] < A [left] && A[left] >= A[right] ) 
		{
			SWAP(A, parent, left);
			heapSort_insert(A, parent, Size);
		}
		if(A[parent] < A[right] )
		{
			SWAP(A, parent, right);
			heapSort_insert(A, parent, Size);
		}
	}
	else if( current%2 == 1 )
	{
		parent = (current) / 2 ;
		left = 2 * parent + 1 ;
		right = 2 * parent + 2;
		if(A [parent] < A [left] && A[left] >= A[right] ) 
		{
			SWAP(A, parent, left);
			heapSort_insert(A, parent, Size);
		}
		if(A[parent] < A[right] )
		{
			SWAP(A, parent, right);
			heapSort_insert(A, parent, Size);
		}
	}
}

void heapSort(int A[], int root, int Size) // 마지막 인덱스를 
{
	int parent, left, right;
	parent = root;
	left = 2 * parent + 1;
	right = 2 * parent + 2;
	if(Size >= 1)
	{
		if(Size == 1)
		{
			if(A[ 1 ] > A[ 0 ]) SWAP(A, 0, 1);
			SWAP(A,0,Size);
		}
		else if(Size == 2)
		{
			if( A[0] < A[1] && A[1] > A[2]) SWAP(A, 0, 1); 
			else if( A[0] < A[2] ) SWAP(A,0,1);
			SWAP(A,0,Size);
			heapSort(A, 0, Size-1);
		}
		else if(left >= Size || right >= Size)
		{ // 이때 left 가 Size 값보다 같거나 크거나, 또는 right 값이 Size 값보다 같거나 큰경우.0 1 2
			// Size가 2이면, 2는 가면안되지. 
			SWAP(A, 0, Size);
			
			heapSort(A, 0, Size - 1);
		}
		else if( A[ left ] > A[ parent ] && A[ left ] >= A[ right ] )
		{ // 좌측 자식노드가 더 큼			
			SWAP(A, left, parent);
			heapSort(A, left, Size);
		}
		else if( A[ right ] > A[ parent ] )
		{ // 우측 자식노드가 더 큼
			SWAP(A, right, parent);
			heapSort(A, right, Size);
		}
		else
		{
			SWAP(A, 0, Size);
			heapSort(A, 0, Size-1);
		}
	}

}

int main()
{
	int t, idx = 0;
	cin >> t ;
	int count = t;

	int sol[200000] = {0,};
	while(t--)
	{
		scanf("%d", &sol[idx++]); // 설마
		heapSort_insert(sol, idx-1 , idx);
	}
    //heapSort(sol,idx - 1, idx)
	
	heapSort( sol, 0 , count-1); // 끝 인덱스가 count-1 
	


	int n1, n2, num = sol[0] + sol[count-1];
	int i = 0 , j = count-1;
	while(i < j)
	{		
			if( (sol[i] + sol[j]) == 0 )
			{
				n1 = i ; n2 = j;
				break; // 종료
			}
			else if( (sol[i] + sol[j]) < 0 )  
			{ // 비교값이 음수이고, 이전비교값의 절대값보다, 현재비교값의 절대값이 더 작으면,저장
				if( abs(num) >= abs(sol[i] + sol[j]) )
				{
					n1 = i++ ; n2 = j;
					num = sol[n1] + sol[n2];
				}
				else i++;
			}
			else if( (sol[i] + sol[j]) > 0 ) 
			{ // 비교값이 양수이고, 이전비교값의 절대값보다, 현재비교값의 절대값이 더 작으면,저장
				if( abs(num) >= abs(sol[i] + sol[j]) )
				{  
					n1 = i ; n2 = j--;
					num = sol[n1] + sol[n2];
				}
				else j--;
			}
	}
	printf("%d %d\n",sol[n1],sol[n2]);
	return 0;
}
