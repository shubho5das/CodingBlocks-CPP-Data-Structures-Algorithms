// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll Q,i,cost,type;
    stack<ll> X;

    cin>>Q;
    for(i=1 ; i<=Q ; i++){

    	cin>>type;

    	if(type == 2){
    		cin>>cost;
    		X.push(cost);
    	}
    	else if(type == 1){

    		if(X.empty()){
    			cout<<"No Code\n";
    			continue;
    		}

    		cout<<X.top()<<"\n";
    		X.pop();
    	}
    }
	
    return 0;
}



