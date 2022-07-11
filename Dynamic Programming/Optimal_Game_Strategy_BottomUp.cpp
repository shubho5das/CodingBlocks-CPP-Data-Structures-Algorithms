#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"


ll find_max_score(ll A[],ll n){
	// Bottom Up Appoach - my Logic!

	ll i,j,col;

	ll dp[n+5][n+5] = {0};	

	// Base Case
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

			if( (i+j)%2 != 0){
				// My Turn
				dp[i][j] = max( (A[i]+dp[i+1][j]) , (A[j]+dp[i][j-1]) );
			}
			else{
				// Opponent's Turn
				dp[i][j] = min( (0 + dp[i+1][j]) , (0 + dp[i][j-1]) );
			}

			i += 1;
			j += 1;
		}
	}

	return dp[0][n-1];

}

int main(){

	ll n,i;

	cin>>n;

	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}
	
	cout<<find_max_score(A,n)<<"\n";	

	return 0;
}