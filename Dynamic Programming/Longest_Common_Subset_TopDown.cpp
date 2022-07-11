/*
	Longest Common Subset (LCS)

	"Given two strings S and T, 
	 determine the length of the Longest Common Subset."
	
	Time Complexity = O(nm) (2D dp)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll find_LCS_length(string &S,string &T,ll i,ll j,ll dp[][1005]){

	ll op1,op2,ans;

	// Base Case
	if(i == S.length() || j == T.length() ){
		return 0;
	}

	// Recursive Case

	// Look Up
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	if(S[i] == T[j]){
		ans = 1 + find_LCS_length(S,T,i+1,j+1,dp);
	}
	else{
		op1 = find_LCS_length(S,T,i+1,j,dp);
		op2 = find_LCS_length(S,T,i,j+1,dp);

		ans = max(op1,op2);
	}

	dp[i][j] = ans;
	return ans;
}


ll dp[1005][1005];

int main(){

	ll i,j;

	for(i=0 ; i<=1002 ; i++){
		for(j=0 ; j<=1002 ; j++)
			dp[i][j] = -1;
	}
	
	string S = "ABCD";
	string T = "ABEDG";

	i = 0;
	j = 0;
	cout<<find_LCS_length(S,T,i,j,dp);

	return 0;
}