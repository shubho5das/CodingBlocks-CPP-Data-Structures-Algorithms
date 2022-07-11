#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll check_sorted(ll A[],ll n)
{
	// Base Case
	if(n==1)
		return(1);

	// Recursive Case
	if( A[0]<A[1] && check_sorted(A+1,n-1)==1 ) // NOTE: Base address of remaining array is (A+1)
	{
		return(1);
	}

	return(0);
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,i,check;

	cin>>n;
	ll A[n];
	for(i=0;i<n;i++)
		cin>>A[i];

	check = check_sorted(A,n);

	if(check==1)
		cout<<"true\n";
	else
		cout<<"false\n";

	return 0;
}
