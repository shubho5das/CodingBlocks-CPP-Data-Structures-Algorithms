#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(15)<<x<<"\n";

const ll N_max = 1e2;
const ll K_max = 1e5;

ll A[N_max+5];

ll dp[N_max+5][K_max+5];

ll find_ways(ll A[],ll n,ll k){

	ll i,j;

	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<=k ; j++)
			dp[i][j] = 0;
	}

	// Base Case
	for(j=0 ; j<=k ; j++){
		if(j <= A[0])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}

	// General Case

	for(i=1 ; i<n ; i++){
		for(j=0 ; j<=k ; j++){
			
			dp[i][j] = 0;

			dp[i][j] += dp[i-1][j];
			dp[i][j] %= mod;

			if((j-1) >= 0){
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= mod;
			}

			if( (j-1-A[i]) >= 0){
				dp[i][j] = ( dp[i][j] - dp[i-1][(j-1-A[i])] + mod )%mod;
			}

			dp[i][j] %= mod;
		}
	}

	return dp[n-1][k];

}

void run_case(){

	ll n,k,i;

	cin>>n>>k;

	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	cout<<find_ways(A,n,k)<<"\n";
	
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin>>T;
    while(T--)
        run_case();

    return 0;
}