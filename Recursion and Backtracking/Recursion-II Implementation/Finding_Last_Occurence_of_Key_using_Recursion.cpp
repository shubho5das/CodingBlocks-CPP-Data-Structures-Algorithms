// File Name: Finding_Last_Occurence_of_Key_using_Recursion
#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll search_last_occurence(ll A[],ll n,ll key)
{
	ll index;

	// Base Case
	if(n==0)
		return(-1);

	// Recursive Case
	index = search_last_occurence(A+1,n-1,key);

	if(index == -1)
	{
		if(A[0] == key)
			return 0;
		else
			return -1;
	}
	else
		return(index + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll n,index,key;
	ll A[] = {1,2,7,3,7,6};

	n = sizeof(A)/sizeof(A[0]);
	key = 7;
	index = search_last_occurence(A,n,key);
	cout<<index<<"\n";

	return 0;
}
