#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,num,i,k;

    list<ll> L;
    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	L.push_back(num);
    }
    cin>>k;
    for(i=1 ; i<=k ; i++){
    	num = L.back();
    	L.push_front(num);
    	L.pop_back();
    }

    for(auto num:L)
    	cout<<num<<" ";
    cout<<"\n"; 

    return 0;
}


