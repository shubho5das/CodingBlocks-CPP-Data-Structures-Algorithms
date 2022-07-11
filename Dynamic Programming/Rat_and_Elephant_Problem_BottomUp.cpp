#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll dp[100][100];

ll count_rat_ways(ll R,ll C){

	ll i,j;

	memset(dp,-1,sizeof(dp));

	// Base Case
	dp[0][0] = 1;
	for(j=1 ; j<C ; j++)
		dp[0][j] = 1;
	for(i=1 ; i<R ; i++)
		dp[i][0] = 1;

	// General Case

	for(i=1 ; i<R ; i++){
		for(j=1 ; j<C ; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[R-1][C-1];
}

ll count_elephant_ways(ll R,ll C){

	ll i,j,k;

	memset(dp,-1,sizeof(dp));

	// Base Case
	dp[0][0] = 1;

	for(j=1 ; j<C ; j++){
		dp[0][j] = 0;
		for(k=0 ; k<=(j-1) ; k++)
			dp[0][j] += dp[0][k];
	}

	for(i=1 ; i<R ; i++){
		dp[i][0] = 0;
		for(k=0 ; k<=(i-1) ; k++)
			dp[i][0] += dp[k][0];
	}


	for(i=1 ; i<R ; i++){
		for(j=1 ; j<C ; j++){

			dp[i][j] = 0;
			// Ways from Left
			for(k=0 ; k<=(j-1) ; k++)
				dp[i][j] += dp[i][k];
			// Ways from Up
			for(k=0 ; k<=(i-1) ; k++)
				dp[i][j] += dp[k][j];
		}
	}

	// for(i=0 ; i<R ; i++){
	// 	for(j=0 ; j<C ; j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";

	return dp[R-1][C-1];

}


int main(){

	ll R,C;

	cin>>R>>C;

	cout<<count_rat_ways(R,C)<<"\n";
	cout<<count_elephant_ways(R,C)<<"\n";

	return 0;
}