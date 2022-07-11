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

    ll n,i,num;
    priority_queue<ll> P1;						  // max heap 
    priority_queue<ll,vector<ll>,greater<ll>> P2; // min heap

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	P1.push(num);
    	P2.push(num);
    }

    for(i=0 ; i<n ; i++){
    	cout<<P1.top()<<" ";
    	P1.pop();
    }
    cout<<"\n";

    for(i=0 ; i<n ; i++){
    	cout<<P2.top()<<" ";
    	P2.pop();
    }
    cout<<"\n";
   
    return 0;
}

