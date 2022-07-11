#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll fast_power(ll a,ll n)
{
	ll small_ans,ans;

	// Base Case
	if(n==0)
		return 1;

	// Recursive Case
	if(n%2==0)
	{
		small_ans = ( fast_power(a,n/2));
			
		ans = small_ans * small_ans;
		return(ans);
	}
	else
	{
		small_ans = ( fast_power(a,n/2));
		
		ans = ( a * small_ans * small_ans );
		return(ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a,n,ans;

	cin>>a>>n;
	ans = fast_power(a,n);
	cout<<ans<<"\n";

	return 0;
}