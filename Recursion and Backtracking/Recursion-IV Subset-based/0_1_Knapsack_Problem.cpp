#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

ll max_profit(ll N,ll C,ll wt[],ll price[])
{
	ll ans,inc,exc;

	// Base Case
	if(N==0 || C==0)
		return 0;

	// Recursive Case

	inc = 0;
	exc = 0;
	// Case 1: Including the Nth item
	if(wt[N-1]<=C)
		inc = price[N-1] + max_profit(N-1,C-wt[N-1],wt,price);
	// Case 2: Excluding the Nth item
	exc = max_profit(N-1,C,wt,price);

	ans = max(inc,exc);
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N,C,ans;

	ll wt[] = {1,2,3,5};
	ll price[] = {40,20,35,100};

	N = 4;
	C = 7;
	ans = max_profit(N,C,wt,price);
	cout<<ans<<"\n";

	return 0;
}