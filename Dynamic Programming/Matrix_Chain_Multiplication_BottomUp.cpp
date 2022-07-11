#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_min_cost(ll dim[],ll n){
	// Bottom-Up Approach - 2D DP

	ll N,i,j,k,current_cost,min_cost,col;

	ll dp[100][100] = {0};

	N = (n-1); // number of Matrices

	// Filling diagonal starting with col=0, with zeroes (Base Case)
	i=0 , j=0;
	while(j < N){
		dp[i][j] = 0;
		i += 1;
		j += 1;
	}

	for(col=1 ; col<N ; col++){

		i = 0;
		j = col;


		while(j < N){

			min_cost = LLONG_MAX;

			for(k=i ; k<=(j-1) ; k++){

				current_cost = dp[i][k] + dp[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
				min_cost = min(min_cost,current_cost);
			}

			dp[i][j] = min_cost;

			i += 1;
			j += 1;
		}
	}

	return dp[0][N-1];

}

int main(){

	ll n;

	ll dim[] = {4,2,3,1,3};
	n = sizeof(dim)/sizeof(dim[0]);

	cout<<find_min_cost(dim,n)<<"\n";
	
	return 0;
}