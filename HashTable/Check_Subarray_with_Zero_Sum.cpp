#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

bool check_zero_sum(ll A[],ll n){

	ll cum_sum,i;

	unordered_set<ll> P;
	cum_sum = 0;
	P.insert(0);
	for(i=0 ; i<n ; i++){
		cum_sum += A[i];
		if(P.find(cum_sum) != P.end())
			return true;

		P.insert(cum_sum);
	}
	return false;
}

void run_case(){
	
	ll i,n;

    cin>>n;     // 5
    ll A[n];    // 6 -1 2 1 -1
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	bool check = check_zero_sum(A,n);
	if(check == true)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin>>T;
    while(T--)
    	run_case();

    return 0;
}