// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

ll find_min_cost(ll A[],ll n){

	ll num,i,cost,sum,minimum;

	priority_queue<ll,vector<ll>,greater<ll>> P(A,A+n);

	sum = P.top();
	P.pop();
	cost = 0;
	while(P.size() >= 1){
		minimum = P.top();
		P.pop();
		sum = sum + minimum;
		cost += sum;
	}

	return cost;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,cost;

    cin>>n;
    ll A[n]; // 4 3 2 6
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }

    cost = find_min_cost(A,n);
    cout<<cost<<"\n";
    
	return 0;
}



