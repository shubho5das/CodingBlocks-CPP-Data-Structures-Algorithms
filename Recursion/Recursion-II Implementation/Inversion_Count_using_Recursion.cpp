#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll merge(ll A[],ll s,ll e)
{
	ll mid,i,j,k,count;
	ll temp[10000];

	mid = (s+e)/2;
	i = s;
	j = (mid +1);
	k = s;

	count = 0; // cross inversions
	while(i<=mid && j<=e)
	{
		if(A[i]<=A[j]) // A[i] is smaller
		{
			temp[k] = A[i];

			i += 1;
			k += 1;
		}
		else if(A[j] < A[i]) // A[j] is smaller ie, inversion occurs
		{
			temp[k] = A[j];

			count += (mid - i + 1);

			j += 1;
			k += 1;
		}
	}

	// If we have exhaused elements of the right array, but the left array elements are still remaining.
	while(i<=mid)
	{
		temp[k] = A[i];

		i += 1;
		k += 1;
	}
	// If we have exhausted elements of the left array, but the right array elements are still remaining.
	while(j<=e)
	{
		temp[k] = A[j];

		j += 1;
		k += 1;
	}

	//Copying contents of temp[] to the original array, A[] 
	// (So that, the changes made in A[] gets reflected)
	for(i=s;i<=e;i++)
		A[i] = temp[i];

	return(count);
}

ll inversion_count(ll A[],ll s,ll e) // Exactly same as merge sort() Function
{
	ll mid,x,y,z,ans;

	// Base Case
	if(s>=e)
		return 0;

	// Recursive Case

	mid = (s+e)/2;

	x = inversion_count(A,s,mid);
	y = inversion_count(A,mid+1,e);
	z = merge(A,s,e); // cross inversions

	ans = (x + y + z);
	return(ans); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		

	ll n,ans;

	// ll A[] = {1,5,2,6,3,0};
	ll A[] = {2,4,1,3,5};
	n = sizeof(A)/sizeof(A[0]);

	ans = inversion_count(A,0,n-1);
	cout<<ans<<"\n";

	return 0;
}