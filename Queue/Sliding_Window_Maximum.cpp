#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void maximum_sliding_window(ll A[],ll n,ll k){

	ll i,max;	
	deque<ll> Q(k);

	// Processing 1st k elements
	for(i=0 ; i<k ; i++){
		// Removing the useless elements from the window
		while( (Q.size() >= 1) && (A[Q.back()] <= A[i] ) ){
			Q.pop_back();
		}
		Q.push_back(i);
	}

	max = A[Q.front()];
	cout<<max<<" ";

	// Processing the remaining elements
	for( ; i<=(n-1) ; i++){

		// Step 1: Removing elements which are no longer part of window
		while( (Q.size()>=1) && (Q.front()<=(i-k)) )
			Q.pop_front();
		// Step 2: Removing the useless elements from the Window
		while( (Q.size()>=1) && (A[Q.back()]<=A[i]) )
			Q.pop_back();
		// Step 3: Adding the new element
		Q.push_back(i);

		max = A[Q.front()];
		cout<<max<<" ";
	}
	cout<<"\n";
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	

    ll n,k,i,max;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++)
    	cin>>A[i];
    cin>>k;
    maximum_sliding_window(A,n,k);
    
    return 0;
}

