#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll fib(ll n,ll dp[]){

	ll ans;

	// Base Case
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	// Recursive Case

	// Look Up
	if(dp[n] != 0)
		return dp[n];

	ans = fib(n-1,dp) + fib(n-2,dp);
	dp[n] = ans;
	return ans;
}

int main(){

	ll n;

	ll dp[1005] = {0};

	cin>>n;
	cout<<fib(n,dp)<<"\n";

	return 0;
}