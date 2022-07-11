#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll f(ll N)
{
	ll a,b,ans;

	// Base Case
	if(N==2)
		return 3;
	if(N==1)
		return 2;

	// Recursive Case
	a = f(N-1);
	b = f(N-2);

	ans = (a + b);
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N,ans;

	cin>>N;
	ans = f(N);
	cout<<ans<<"\n";
	
	return 0;
}