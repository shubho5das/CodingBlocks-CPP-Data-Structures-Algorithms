/*
Problem:
Farmer John has built a new long barn, with N (2 <= N <= 100,000) 
stalls. The stalls are located along a straight line at positions 
x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become 
aggressive towards each other once put into a stall. To prevent the 
cows from hurting each other, FJ wants to assign the cows to the 
stalls, such that the minimum distance between any two of them is as
large as possible. 
 What is the largest minimum distance?


*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

bool check(ll A[],ll n,ll x,ll C){

	ll i,count,current_seperation,prev;

	count = 0;
	
	// Placing 1st Cow at the first stall
	prev = A[0];
	count += 1;
	for(i=1 ; i<n ; i++){
		if( (A[i] - prev) >= x){
			// Placing cow at ith location
			count += 1;
			prev = A[i];

			if(count == C)
				return true;
		}
	}

	return false;
}

void run_case(){

	ll n,C,i,s,e,mid,ans;

	cin>>n>>C;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}
	sort(A,A+n);

	// Binary Search Algorithm
	s = 0;
	e = (A[n-1] - A[0]);
	while( s <= e){

		mid = (s+e)/2;

		if(check(A,n,mid,C) == true){
			ans = mid;
			s = (mid + 1);
		}
		else
			e = (mid - 1);
	}

	cout<<ans<<"\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    cin>>T;
    while(T--)
        run_case();

    return 0;
}