#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll range_sum(ll cum_sum[],ll i,ll j){

	return (cum_sum[j+1] - cum_sum[i]);
}

ll find_min_smoke(ll A[],ll n,ll cum_sum[]){
	// Bottom Up Approach- 2D DP
	// almost ditto same as MCM, xD!

	ll current_smoke,min_smoke,i,j,k,col;

	ll dp[100][100] = {0};

	// Base Case: Filling diagonal with col=0 ,with 0
	i = 0;
	j = 0;
	while(j < n){
		dp[i][j] = 0;
		i += 1;
		j += 1;
	}

	for(col=1 ; col<n ; col++){

		i = 0;
		j = col;

		while(j < n){

			min_smoke = LLONG_MAX;

			for(k=i ; k<=(j-1) ; k++){

				current_smoke = dp[i][k] + dp[k+1][j] + ( (range_sum(cum_sum,i,k) % 100) * (range_sum(cum_sum,k+1,j) % 100) );
				min_smoke = min(min_smoke,current_smoke);
			}

			dp[i][j] = min_smoke;

			i += 1;
			j += 1;
		}
	}

	return dp[0][n-1];

}

int main(){

	ll n,i,j;

	while(cin>>n){

		ll A[n];
		for(i=0 ; i<n ; i++){
			cin>>A[i];
		}

		ll cum_sum[n+1];
		cum_sum[0] = 0;
		for(i=1 ; i<=n ; i++)
			cum_sum[i] = cum_sum[i-1] + A[i-1];

		cout<<find_min_smoke(A,n,cum_sum)<<"\n";
		
	}

	
	return 0;
}