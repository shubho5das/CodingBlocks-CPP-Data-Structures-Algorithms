#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_min_coin_change(ll n,ll coin[],ll c,ll dp[]){

	ll ans,i,current_option;

	// Base Case
	if(n == 0)
		return 0;

	// Recursive Case

	// Look Up
	if(dp[n] != 0)
		return dp[n];

	ans = LLONG_MAX;
	for(i=0 ; i<c ; i++){

		current_option = inf;
		if(n >= coin[i])
			current_option = 1 + find_min_coin_change((n-coin[i]),coin,c,dp);

		ans = min(ans,current_option);
	}

	dp[n] = ans;
	return ans;
}

int main(){

	ll n,c;

	ll coin[] = {1,2,5,10,20,50,100,200,500,2000};
	c = sizeof(coin)/sizeof(coin[0]);

	ll dp[5005] = {0};

	cin>>n;
	cout<<find_min_coin_change(n,coin,c,dp);

	return 0;
}