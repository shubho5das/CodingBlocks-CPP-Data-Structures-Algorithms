#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll partition( ll A[], ll s, ll e)
{
	ll i,j,pivot;
	ll pivot_index;

	i = (s-1);
	j = s;

	pivot = A[e];

	for( ; j<=(e-1) ; )
	{
		if( A[j] <= pivot)
		{
			// Merge the array element in the Smaller Region
			i += 1;
			swap(A[i],A[j]);
		}

		// Keep expanding the Larger Portion
		j += 1;
	}

	// Finally, place the pivot element in the correct position
	pivot_index = (i+1);
	swap(A[e],A[pivot_index]);

	return(pivot_index);
}

void quick_sort(ll A[],ll s,ll e)
{
	ll p;

	// Base Case
	if( s >= e )
		return;

	// Recursive Case

	p = partition(A,s,e);
	
	quick_sort(A,s,p-1); // Left Part
	quick_sort(A,p+1,e); // Right Part
}

int main()
{
	ll i,n;

	ll A[] = {2,7,8,6,1,5,4};

	n = sizeof(A)/sizeof(A[0]);

	quick_sort(A,0,n-1);

	for(i=0 ; i<n ; i++)
		cout<<A[i]<<" ";
	cout<<"\n";

	return 0;
}