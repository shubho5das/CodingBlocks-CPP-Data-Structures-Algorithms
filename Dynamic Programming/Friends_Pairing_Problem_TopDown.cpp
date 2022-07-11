#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll nCr(ll n,ll r){
	ll ans,i;
    
    if (r> n) 
    	return 0;
    if (r * 2 > n)  
    	r = n-r;  
    if (r == 0) 
    	return 1;
 
    ans = n;
    for(i = 2; i <= r; i++){
        ans =  ans * (n-i+1);
        ans = ans/i;
    }
    return(ans);
}

ll find_ways(ll n,ll dp[]){
	// TopDown Approach

	ll ans,i;

	// Base Case
	if(n == 1)
		return 1;

	if(n == 2)
		return 2;

	// Recursive Case

	// Look Up
	if(dp[n] != 0)
		return dp[n];

	ans = 1*find_ways(n-1,dp) + nCr(n-1,1)*find_ways(n-2,dp);

	dp[n] = ans;
	return ans;
}

int main(){

	ll n;

	ll dp[1000] = {0};

	cin>>n;
	cout<<find_ways(n,dp)<<"\n";

	return 0;
}