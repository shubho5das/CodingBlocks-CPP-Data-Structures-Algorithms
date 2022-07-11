#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_min_step(ll n){

	ll op1,op2,op3,i;

	ll dp[1005] = {0};

	dp[1] = 0;
	for(i=2 ; i<=n ; i++){

		if(i%3 == 0)
			op1 = dp[i/3] + 1;
		else
			op1 = inf;

		if(i%2 == 0)
			op2 = dp[i/2] + 1;
		else
			op2 = inf;

		op3 = dp[i-1] + 1;

		dp[i] = min({op1,op2,op3});
	}

	return dp[n];
}


int main(){

	ll n;

	cin>>n;
	cout<<find_min_step(n)<<"\n";

	return 0;
}