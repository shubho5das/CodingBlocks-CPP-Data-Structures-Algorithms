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

    ll Q,k,i,type,x,y,dist;

    cin>>Q>>k;
    priority_queue<ll> P;

    while(Q--){
    	cin>>type;
    	if(type == 1){
    		cin>>x>>y;
    		dist = x*x + y*y;
    		P.push(dist);
    		if(P.size() > k)
    			P.pop();
    	}
    	else{
    		cout<<P.top()<<"\n";
    	}
    }

    return 0;
}



