#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

bool is_sorted(ll A[],ll n){

	bool result;

	// Base Case
	if(n == 1){
		return true;
	}
	// Recursive Case
	result = is_sorted(A+1,n-1);
	if( (A[0]<A[1]) && (result == true) )
		return true;
	return false;

}

ll A[1002];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,i;
	bool result;

	cin>>n;
	for(i=0 ; i<n ; i++)
		cin>>A[i];
	result = is_sorted(A,n);
	if(result == true)
		cout<<"true\n";
	else
		cout<<"false\n";
	
	return 0;
}