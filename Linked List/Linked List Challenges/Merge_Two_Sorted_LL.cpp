#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T,n1,n2,num,i;

    cin>>T;
    while(T--){

    	cin>>n1;
    	list<ll> L1;
    	for(i=0 ; i<n1 ; i++){
    		cin>>num;
    		L1.push_back(num);
    	}
    	cin>>n2;
    	list<ll> L2;
    	for(i=0 ; i<n2 ; i++){
    		cin>>num;
    		L2.push_back(num);
    	}

    	L1.merge(L2);

    	for(auto num:L1)
    		cout<<num<<" ";
    	cout<<"\n";
    }
    
    return 0;
}



