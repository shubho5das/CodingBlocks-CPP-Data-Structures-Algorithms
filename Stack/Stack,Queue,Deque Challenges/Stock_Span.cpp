// KEEP CALM and Enjoy the Problem B-)
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

    ll n,i;

    cin>>n;
    ll price[n];
    ll span[n];
    for(i=0 ; i<n ; i++){
    	cin>>price[i];
    }

    find_span(price,n,span);

    for(i=0 ; i<n ; i++){
    	cout<<span[i]<<" ";
    }
    cout<<"END\n";
    
    return 0;
}


