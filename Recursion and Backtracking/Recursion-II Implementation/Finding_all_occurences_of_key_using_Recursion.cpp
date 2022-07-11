#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

/* Here, we have simply converted the itertive Linear Search into a Recursive Function.
Nothing too cool about it, really! :(
*/
void print_all_occurences(ll A[],ll i,ll n,ll key) 
//Here, i is the starting index and n is the ending index (exclusive, just like v.end() ) 
{

	// Base Case
	if(i==n)
		return;

	// Recursive Case
	if(A[i]==key)
	{
		cout<<i<<" ";
	}

	print_all_occurences(A,i+1,n,key);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,key,i;
	ll A[] = {1,2,3,7,4,5,6,7,10};

	n = sizeof(A)/sizeof(A[0]);
	key = 7;
	print_all_occurences(A,0,n,key);
	cout<<"\n";
	
	return 0;
}
