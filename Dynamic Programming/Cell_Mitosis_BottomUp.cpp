#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll dp[100005] = {0};

ll find_min_cost(ll n,ll x,ll y,ll z){
	// Bottom-Up Approach

	ll i;

	memset(dp,0,sizeof(dp));

	dp[1] = 0;

	for(i=2 ; i<=n ; i++){

		if(i%2 == 0)
			dp[i] = min((dp[i/2] + x),(dp[i-1] + y));
		else
			dp[i] = min((dp[i-1] + y),(dp[(i+1)/2] + x + z));
	}

	return dp[n];

}

int main(){

	ll n,x,y,z;

	cin>>n;
	cin>>x>>y>>z;

	cout<<find_min_cost(n,x,y,z)<<"\n";

	return 0;
}