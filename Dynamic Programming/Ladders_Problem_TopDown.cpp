#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll find_way(ll n,ll k,ll dp[]){
	// Time Complexity = O(n.k)

	ll ans,i;

	// Base Case
	if(n == 0)
		return 1;

	// Recursive Case

	// Look Up
	if(dp[n] != 0)
		return dp[n];

	ans = 0;
	for(i=1 ; i<=k ; i++){
		if((n-i) >= 0){
			ans += find_way(n-i,k,dp);
		}
	}

	dp[n] = ans;
	return ans;
}

int main(){

	ll n,k;

	ll dp[1005] = {0};

	cin>>n>>k;
	cout<<find_way(n,k,dp)<<"\n";

	return 0;
}