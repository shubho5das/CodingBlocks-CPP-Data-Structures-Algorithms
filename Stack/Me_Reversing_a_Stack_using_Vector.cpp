#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,num,n;

    cin>>n;
    stack<ll> X;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	X.push(num);
    }
    vector<ll> V;
    // Step 1: Transfering elements from stack to vector
    for(i=0 ; i<n ; i++){
    	num = X.top();
    	X.pop();
    	V.push_back(num);
    }
    // Step 2: Reversing the Vector
    reverse(V.begin(),V.end());
    // Step 3: Tranfering elements back from vector to stack
    for(i=0 ; i<n ; i++){
    	num = V[i];
    	X.push(num);
    }

    for(i=0 ; i<n ; i++){
    	cout<<X.top()<<" ";
    	X.pop();
    }
    cout<<"\n";

    return 0;
}

