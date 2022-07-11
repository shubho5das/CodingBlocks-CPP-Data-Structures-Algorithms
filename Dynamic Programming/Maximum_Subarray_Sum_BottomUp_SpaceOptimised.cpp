#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll find_max_subarray_sum(ll A[],ll n){
	// Bottom Up DP (Kadane's Algo)

	ll current_sum,max_subarray_sum,i;

	current_sum = A[0];
	max_subarray_sum = A[0];

	for(i=1 ; i<n ; i++){

		current_sum = max(current_sum+A[i],A[i]);

		max_subarray_sum = max(max_subarray_sum,current_sum);
	}

	return  max_subarray_sum;
}

int main(){

	ll n;

	ll A[] = {-2,-3,4,-1,-2,1,5,-3};
	n = sizeof(A)/sizeof(A[0]);

	cout<<find_max_subarray_sum(A,n)<<"\n";

	return 0;
}