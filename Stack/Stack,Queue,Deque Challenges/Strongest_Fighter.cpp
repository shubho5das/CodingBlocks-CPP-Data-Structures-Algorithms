// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void find_strongest_fighter(ll A[],ll n,ll k){

	ll i;
	deque<ll> Q;

	//Processing the 1st k elements
	for(i=0 ; i<k ; i++){
		while(Q.size() >= 1 && A[Q.back()] <= A[i])
			Q.pop_back();
		Q.push_back(i);
	}
	cout<<A[Q.front()]<<" ";

	// Processing the remaining elements
	for( ; i<=(n-1) ; i++){

		// Step 1: Removing the left element, not part of window anymore
		while( Q.size()>= 1 && Q.front()<=(i-k) )
			Q.pop_front();
		// Step 2: Removing the useless elements from the window
		while( Q.size()>=1 && A[Q.back()] <= A[i])
			Q.pop_back();
		// Step 3: Adding the new element
		Q.push_back(i);

		cout<<A[Q.front()]<<" ";
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll n,i,k;

	cin>>n;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	cin>>k;
	find_strongest_fighter(A,n,k);
	cout<<"\n";

    return 0;
}



