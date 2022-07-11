// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void insert_at_bottom(stack<ll> &X,ll x){

	ll data;

	// Base Case
	if(X.size() == 0){
		X.push(x);
		return;
	}

	// Recursive Case
	data = X.top();
	X.pop();
	insert_at_bottom(X,x);
	X.push(data);
}

void reverse_stack(stack<ll> &X){
	
	ll temp;

	// Base Case
	if(X.size() == 0)
		return;

	// Recursive Case
	temp = X.top();
	X.pop();
	reverse_stack(X);
	insert_at_bottom(X,temp);

}

void print_stack(stack<ll> X){
	while(X.size() >= 1){
		cout<<X.top()<<"\n";
		X.pop();
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll n,i,num;
	stack<ll> X;

	cin>>n;
	for(i=0 ; i<n ; i++){
		cin>>num;
		X.push(num);
	}

	//print_stack(X);
	reverse_stack(X);
	print_stack(X);

    return 0;
}



