#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll find_max_profit(ll n,ll price[],ll dp[]){
	// Time Complexity = O(n.n) = O(n^2)

	ll i,ans;

	// Base Case
	if(n == 0){
		return 0;
	}

	// Recursive Case

	// Look Up
	if(dp[n] != 0){
		return dp[n];
	}

	ans = LLONG_MIN;
	for(i=1 ; i<=n ; i++){
		ans = max(ans,(price[i-1] + find_max_profit(n-i,price,dp)));
	}

	dp[n] = ans;
	return ans;

}

int main(){

	ll n,i;

	ll dp[1005] = {0};

	n = 8;
	ll price[] = {1,5,8,9,10,17,17,20};

	cout<<find_max_profit(n,price,dp);

	return 0;
}