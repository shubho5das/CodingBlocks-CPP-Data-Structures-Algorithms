#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void merge(ll A[],ll s,ll e)
{
	ll mid,i,j,k;
	ll temp[100];

	mid = (s+e)/2;
	i = s;
	j = (mid+1);
	k = s;
	
	// Merging the 2 Sorted Arrays using 2-pointer approach
	while(i<=mid && j<=e)
	{
		if(A[i] <= A[j]) // A[i] is smaller
		{
			temp[k] = A[i];
			i += 1;
			k += 1;
		}
		else if(A[j] < A[i]) // A[j] is smaller
		{
			temp[k] = A[j];
			j += 1;
			k += 1;
		}	
	}

	// If i has not reached the end yet
	while(i<=mid)
	{
		temp[k] = A[i];
		i += 1;
		k += 1;
	}
	// If j has not reached the end yet
	while(j<=e)
	{
		temp[k] = A[j];
		j += 1;
		k += 1;
	}

	// Finally, copying the contents of temp[] to the original array A[]
	for(i=s ; i<=e ; i++)
		A[i] = temp[i];
}

void merge_sort(ll A[],ll s,ll e)
{
	ll mid;

	// Base Case
	
	if(s>=e)
		return;

	// Recursive Case

	// Step 1: Divide
	mid = (s+e)/2;

	// Step 2: Sort 
	merge_sort(A,s,mid);
	merge_sort(A,mid+1,e);

	// Step 3: Merge back
	merge(A,s,e);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll i,n;
	ll A[] = {5,6,1,2,4,0};

	n = sizeof(A)/sizeof(A[0]);

	
	merge_sort(A,0,n-1);

	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<"\n";

	return 0;
}
