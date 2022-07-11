#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void find_span(ll price[],ll n,ll span[]){

	ll i,current_price;

	stack<ll> X;
	span[0] = 1;
	X.push(0);

	for(i=1 ; i<=(n-1) ; i++){
		
		while( (X.size()>0) && (price[X.top()]<=price[i]) ){
			X.pop();
		}

		// Special Case
		if(X.empty()){
			span[i] = (i+1);
			X.push(i);
			continue;
		}

		span[i] = (i - X.top());
		X.push(i);
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,n;

    ll price[] = {100,80,60,70,60,75,90};
    n = sizeof(price)/sizeof(ll);
    ll span[100] = {0};

    find_span(price,n,span);
    cout<<span[1]<<"\n";
    for(i=0 ; i<n ; i++)
    	cout<<span[i]<<" ";
    cout<<"\n"; 

    return 0;
}


