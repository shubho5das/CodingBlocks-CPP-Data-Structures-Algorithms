#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll multiply(ll a, ll n)
{
	ll ans;

	// Base Case
	if(n==0)
		return(0);

	// Recursive Case
	ans = a + multiply(a,n-1);
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a,n,ans;

	cin>>a>>n;
	ans = multiply(a,n);
	cout<<ans<<"\n";

	return 0;
}