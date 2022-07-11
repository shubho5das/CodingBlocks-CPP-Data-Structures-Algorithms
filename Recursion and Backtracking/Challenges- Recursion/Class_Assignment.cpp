#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

ll f(ll n)
{
	ll ans;

	// Base Case
	if(n==1)
		return 2;
	if(n==2)
		return 3;

	// Recursive Case
	ans = f(n-1) + f(n-2);
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll T,n,ans;

	cin>>T;
	while(T--)
	{
		cin>>n;
		ans = f(n);
		cout<<"#"<<n<<" : "<<ans<<"\n";
	}
	
	return 0;
}

