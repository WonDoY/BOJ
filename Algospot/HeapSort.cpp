#include<iostream>
#include<cstdio>
using namespace std;

void SWAP(int A[], int i, int j)
{
	int temp = A[i]; A[i] = A[j]; A[j] = temp;
}
void heapSort(int A[], int idx, /*const*/int SIZE)
{
	int temp;
	if( (idx/2 - 1) == -1 && idx%2 == 1 )
	{
		SWAP( A, 0, SIZE-1 );
		cout <<SIZE-1 <<  "NOT" << endl;
	}
	else if( ((idx/2) -1) == 0 ) 
	{ // min heap
		if(A[0] < A[1]){ SWAP(A, 0, 1); }
		if(A[0] < A[2]){ SWAP(A, 0, 2); }
		SWAP( A, 0, SIZE-1 );
		cout << SIZE-1 << " "<< A[SIZE-1] << endl;
	}
	else if( A[ (idx/2) -1 ] > 0 && (idx/2)%2 == 0)
	{
		if(A[ (idx/2) -1 ] < A[ (idx/2)*2 + 1 ]) SWAP(A, (idx/2) -1,  (idx/2)*2 + 1 );
		heapSort(A, idx-2, idx);
	}
	else if( A[ (idx/2) -1 ] > 0 && (idx/2)%2 == 1)
	{
		if(A[ (idx/2) -1 ] < A[ (idx/2)*2 + 1 ]) SWAP(A, (idx/2) -1,  (idx/2)*2 + 1 );		
		if(A[ (idx/2) -1 ] < A[ (idx/2)*2 + 2 ]) SWAP(A, (idx/2) -1,  (idx/2)*2 + 2 );
		heapSort(A, idx-1, idx);
	}
}
