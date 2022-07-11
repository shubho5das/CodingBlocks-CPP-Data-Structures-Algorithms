//Reversing_a_Stack_using_only_1_Extra_Stack
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void transfer(stack<ll> &X,stack<ll> &Y,ll n){
	ll i;

	for(i=1 ; i<=n ; i++){
		Y.push(X.top());
		X.pop();
	}
}

void reverse_stack(stack<ll> &X){

	ll n,x,i,j;
	stack<ll> Y;

	n = X.size();

	for(i=1 ; i<=(n-1) ; i++){
		// Step 1
		x = X.top();
		X.pop();
		// Step 2
		transfer(X,Y,(n-i));
		// Step 3
		X.push(x);
		// Step 4
		transfer(Y,X,(n-i));
	}
}

void print_stack(stack<ll> X){

	while(X.size()>0){
		cout<<X.top()<<" ";
		X.pop();
	}
	cout<<"\n";
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<ll> X;
    ll n,i,num;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	X.push(num);
    }

    print_stack(X);
    reverse_stack(X);
  	print_stack(X);

    return 0;
}
