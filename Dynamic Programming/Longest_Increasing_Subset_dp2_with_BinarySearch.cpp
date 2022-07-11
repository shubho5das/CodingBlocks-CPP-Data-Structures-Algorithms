/*
	Finding Longest Increasing Subset (LIS)
	
	Bottom Up dp 
	DP + Binary Search
	
	Time Compexity = O(n.logn)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define inf 1e18

ll find_LIS(ll A[],ll n){
	// Bottom Up DP

	ll i,j,idx,ans;

	ll dp[n+1];

	// Initialising dp[] array	
    dp[0] = -inf;
    for(i=1 ; i<=n ; i++)
        dp[i] = inf;

    // General Case
    for(i=0 ; i<n ; i++){
        // Placing A[i] in the dp[] array (if possible)

        idx = upper_bound(dp,dp+(n+1),A[i]) - dp;
        j = (idx - 1);

        if(A[i] > dp[j] && A[i] < dp[j+1]){
            dp[j+1] = min(A[i],dp[j+1]);
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