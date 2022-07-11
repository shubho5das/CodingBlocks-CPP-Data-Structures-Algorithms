#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	string S;
	ll number,i,n,x;

	cin>>S;
	n = S.length();

	number = 0;
	x = 1;
	for(i=(n-1) ; i>=0 ; i--)
	{
		number += ( (ll)(S[i]-'0') * x);

		x = x*10;
	} 

	cout<<number<<"\n";

	return 0;
}

