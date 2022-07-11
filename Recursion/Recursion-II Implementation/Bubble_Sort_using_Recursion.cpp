#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void bubble_sort(ll A[],ll n)
{
	ll j;

	// Base Case
	if(n==1)
		return;

	// Recursive Case
	for(j=0 ; j<=(n-2) ; j++)
	{
		if(A[j]>A[j+1])
			swap(A[j],A[j+1]);		
	}
	bubble_sort(A,n-1);
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll i,n;
	ll A[] = {5,4,3,1};

	n = sizeof(A)/sizeof(A[0]);

	bubble_sort(A,n);

	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<"\n";

	return 0;
}