/*
	Finding Longest Increasing Subset (LIS)
	
	Assumption: Subset is "strictly" increasing

	Time Compexity = O(n^2) (1-D DP)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll find_LIS(ll A[],ll n,ll i,ll dp[]){
	// Determines length of LIS, ending at index i
	
	ll j,ans,current_option;

	// Base Case

	if(i==0){
		return 1;
	}

	//  Recursive Case

	// Look Up
	if(dp[i] != 0){
		return dp[i];
	} 

	ans = 0;
	for(j=0 ; j<=(i-1) ; j++){

		if(A[j] < A[i]){

			current_option = find_LIS(A,n,j,dp);

			ans = max(ans,current_option);
		}
	}

	ans += 1;

	dp[i] = ans;
	return ans;
}

int main(){

	ll n,i;

	ll dp[1005] = {0};

	ll A[] = {1,5,2,3,4,9,6,10};
	n = sizeof(A)/sizeof(A[0]);

	i = (n-1); // We want to find LIS, ending at index i=(n-1)
	cout<<find_LIS(A,n,i,dp)<<"\n";

	return 0;
}