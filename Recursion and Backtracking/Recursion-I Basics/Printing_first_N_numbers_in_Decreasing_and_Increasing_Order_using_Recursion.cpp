#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void print_decreasing(ll N)
{
	// Base Case
	if(N==0)
	{
		return;        
	}
	
	// Recursive Case
	cout<<N<<" ";
	print_decreasing(N-1);

	return;
}

void print_increasing(ll N)
{
	// Base Case
	if(N==0)
		return;

	// Recursive Case
	print_increasing(N-1);
	cout<<N<<" ";

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N;

	cin>>N;
	print_increasing(N);
	cout<<"\n";
	print_decreasing(N);
	
	return 0;
}