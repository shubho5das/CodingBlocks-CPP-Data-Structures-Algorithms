#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_min_coin_change(ll n,ll coin[],ll c){
	ll i,j;
	
	ll dp[5005] = {0};

	dp[0] = 0;
	for(i=1 ; i<=n ; i++){
		
		dp[i] = LLONG_MAX;
		for(j=0 ; j<c ; j++){
			if(i >= coin[j])
				dp[i] = min(dp[i],(1 + dp[i - coin[j]]));
		}
	}

	return dp[n];
}

int main(){

	ll n,c;

	ll coin[] = {1,2,5,10,20,50,100,200,500,2000};
	c = sizeof(coin)/sizeof(coin[0]);

	
	cin>>n;
	cout<<find_min_coin_change(n,coin,c);

	return 0;
}