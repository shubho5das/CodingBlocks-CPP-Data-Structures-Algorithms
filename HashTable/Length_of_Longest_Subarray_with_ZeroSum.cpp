#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll longest_subrray_of_sum_0(ll A[],ll n){

	ll i,cum_sum,current_length,max_length;

	unordered_map<ll,ll> M;
	// map<cum_sum[i] , index of 1st occurence of key> M

	cum_sum = 0;
	M[0] = -1; 	// We assume 0 is present at (-1)th index (IMP)

	max_length = 0;
	for(i=0 ; i<n ; i++){
		cum_sum += A[i];

		if(M.find(cum_sum) != M.end()){
		// Cum_sum is already present
			current_length = (i - M[cum_sum]);
			max_length = max(max_length,current_length);
		}
		else{
			M[cum_sum] = i;
		}
	}

	return max_length;
}


void run_case(){

	ll i,n,ans;

    cin>>n;     
    ll A[n];    // 0 -1 1 2 5 -5 -2
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	ans = longest_subrray_of_sum_0(A,n);
	cout<<ans<<"\n";

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