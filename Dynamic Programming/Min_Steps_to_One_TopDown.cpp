#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_min_step(ll n,ll dp[]){

	ll op1,op2,op3,ans;

	// Base Case
	if(n==1)
		return 0;

	// Recursive Case 

	// Look Up
	if(dp[n] != 0)
		return dp[n];

	// Case 1
	if(n%3 == 0)
		op1 = 1 + find_min_step(n/3,dp);
	else
		op1 = inf;
	// Case 2
	if(n%2 == 0)
		op2 = 1 + find_min_step(n/2,dp);
	else
		op2 = inf;
	// Case 3
 	op3 = 1 + find_min_step(n-1,dp);

	ans = min({op1,op2,op3});
	dp[n] = ans;
	return ans;
}


int main(){

	ll n;

	ll dp[1005] = {0};

	cin>>n;
	cout<<find_min_step(n,dp)<<"\n";

	return 0;
}