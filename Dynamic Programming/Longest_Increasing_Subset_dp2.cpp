/*
	Finding Longest Increasing Subset (LIS)
	
	Bottom Up dp 
	
	Time Compexity = O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define inf 1e18

ll find_LIS(ll A[],ll n){
	// Bottom Up DP

	ll i,j,ans;

	ll dp[n+1];

	// Initialising dp[] array	
	dp[0] = -inf;
	
	for(i=1 ; i<=n ; i++){
		dp[i] = inf;
	}


	for(i=0 ; i<n ; i++){
		// Placing A[i] in the dp[] array (if possible)

		for(j=0 ; j<n ; j++){

			if(A[i]>dp[j] && A[i]<dp[j+1]){
				dp[j+1] = min(A[i],dp[j+1]);
			}
		}
	}


	for(j=n ; j>=0 ; j--){
		if(dp[j] != inf){
			ans = j;
			break;
		}
	}

	return ans;

}

int main(){

	ll n;

	ll A[] = {1,5,2,4,6};
	n = sizeof(A)/sizeof(A[0]);

	cout<<find_LIS(A,n)<<"\n";

	return 0;
}