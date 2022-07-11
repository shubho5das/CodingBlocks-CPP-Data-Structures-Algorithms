#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll fib(ll n){

	ll a,b,c,i;

	if(n==0)
		return 0;
	if(n==1)
		return 1;

	a = 0;
	b = 1;
	for(i=2 ; i<=n ; i++){
		c = (a + b);

		a = b;
		b = c;
	}

	return c;
}

int main(){

	ll n;

	cin>>n;
	cout<<fib(n)<<"\n";

	return 0;
}