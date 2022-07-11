#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll f(ll N)
{
	ll a,b,c,ans;

	// Base Case
	if(N==0)
		return 1;
		 
	if(N==1)
		return 1;
	if(N==2)
		return 2;
	if(N==3)
		return 4;

	// Recursive Case
	a = f(N-1);
	b = f(N-2);
	c = f(N-3);

	ans = a + b + c;
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