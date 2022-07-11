#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll factorial(ll N)
{
	ll ans;

	// Base Case
	if(N==0)
		return(1);

	// Recursive Case
	ans = N * factorial(N-1);
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N,ans;

	cin>>N;
	ans = factorial(N);
	cout<<ans<<"\n";

	return 0;
}
