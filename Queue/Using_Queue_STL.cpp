#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,n,num;
    queue<ll> Q;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	Q.push(num);
    }
    Q.pop();
    cout<<"Front element = "<<Q.front()<<"\n";
    cout<<"Rear element = "<<Q.back()<<"\n";

    return 0;
}


