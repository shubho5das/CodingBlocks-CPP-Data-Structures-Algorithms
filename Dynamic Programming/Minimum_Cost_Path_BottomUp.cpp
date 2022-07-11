#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll dp[105][105] = {0};

ll find_minimum_cost(ll A[100][100],ll R,ll C){
	// Bottom Up Approach

	ll i,j;

	memset(dp,0,sizeof(dp));

	// Base Case

	dp[0][0] = A[0][0];

	for(j=1 ; j<C ; j++)
		dp[0][j] = dp[0][j-1] + A[0][j];

	for(i=1 ; i<R ; i++)
		dp[i][0] = dp[i-1][0] + A[i][0];

	// General Case

	for(i=1 ; i<R ; i++){
		for(j=1 ; j<C ; j++){

			dp[i][j] = min( (dp[i-1][j] + A[i][j]) , (dp[i][j-1] + A[i][j]) );
		}
	}

	return dp[R-1][C-1];
}

ll A[100][100];

int main(){

	ll R,C,i,j;

	cin>>R>>C;

	for(i=0 ; i<R ; i++){
		for(j=0 ; j<C ; j++)
			cin>>A[i][j];
	}

	cout<<find_minimum_cost(A,R,C)<<"\n";

	return 0;
}
/*
3 3
1 5 2
7 1 1
8 1 3
*/