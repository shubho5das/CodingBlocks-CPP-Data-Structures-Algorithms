/*
Problem:
Given N sticks of lengths L[1], L[2], … L[N] and a positive integer D.
Two sticks can be paired if the difference of their lengths is at most
D.Pair up as many sticks as possible such that each stick is used 
at most once

Problem Tags:
#greedy #sortings

Time Complexity = O(n*logn)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

void run_case(){

	ll i,n,D,count;

	cin>>n>>D;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}
	sort(A,A+n);

	count = 0;
	for(i=0 ; i<=(n-2) ; ){
		if( (A[i+1]-A[i]) <= D ){
			count += 1;
			i += 2;
		}
		else
			i += 1;
	}

	cout<<count<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin>>T;
    while(T--)
        run_case();

    return 0;
}
