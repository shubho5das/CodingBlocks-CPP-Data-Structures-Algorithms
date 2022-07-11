#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll find_way(ll n,ll k){
	// Time Complexity = O(n) 

	ll i;

	ll dp[105] = {0};

	dp[0] = 1; 
	dp[1] = 1;

	for(i=2 ; i<=n ; i++){

		if(i <= k)
			dp[i] = 2*dp[i-1];
		else
			dp[i] = 2*dp[i-1] - dp[(i-1)-k];
	}

	return dp[n];
}

int main(){

	ll n,k;

	cin>>n>>k;
	cout<<find_way(n,k)<<"\n";

	return 0;
}