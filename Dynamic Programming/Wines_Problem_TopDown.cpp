#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_max_profit(ll i,ll j,ll price[],ll yr,ll dp[][105]){

	ll op1,op2,ans;

	// Base Case
	if(i > j)
		return 0;

	// Recursive Case

	// Look Up
	if(dp[i][j] != 0)
		return dp[i][j];

	op1 = (price[i]*yr) + find_max_profit(i+1,j,price,yr+1,dp);
	op2 = (price[j]*yr) + find_max_profit(i,j-1,price,yr+1,dp);

	ans = max(op1,op2);
	dp[i][j] = ans;
	return ans;
}

int main(){

	ll n,i,j,yr;

	ll price[] = {2,3,5,1,4};
	n = sizeof(price)/sizeof(price[0]);

	ll dp[105][105] = {0};

	i = 0;
	j = (n-1);
	yr = 1;
	cout<<find_max_profit(i,j,price,yr,dp)<<"\n";

	return 0;
}