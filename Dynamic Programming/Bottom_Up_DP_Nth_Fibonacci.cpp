#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll fib(ll n){

	ll i;

	ll dp[1005] = {0};

	dp[0] = 0;
	dp[1] = 1;

	for(i=2 ; i<=n ; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){

	ll n;

	cin>>n;
	cout<<fib(n)<<"\n";

	return 0;
}