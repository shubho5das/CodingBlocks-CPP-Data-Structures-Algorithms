// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void print_median(ll A[],ll n){

	ll i;
	ld median;

	priority_queue<ll> P1; 					      // Max Heap
	priority_queue<ll,vector<ll>,greater<ll>> P2; // Min Heap
	median = 0;
	for(i=0 ; i<n ; i++){

		if(A[i] <= median){
			
			// Balancing Operation
			if(P1.size() > P2.size()){
				P2.push(P1.top());
				P1.pop();
			}

			P1.push(A[i]);
		}
		else{
			
			// Balancing Operation
			if(P2.size() > P1.size()){
				P1.push(P2.top());
				P2.pop();
			}

			P2.push(A[i]);
		}

		// Case 1: Even Length
		if(P1.size() == P2.size())
			median = 1.0 * ((P1.top() + P2.top())/2.0);
		// Case 2: Odd Length
		else{
			if(P1.size() > P2.size())
				median = 1.0 * P1.top();
			else
				median = 1.0 * P2.top();
		}

		cout<<median<<" ";
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i;

    cin>>n;
    ll A[n]; // 1 1 5 4 3 0
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }
    print_median(A,n);
    cout<<"\n";

    return 0;
}



