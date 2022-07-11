/* Concept:
	
		Range Sum = k
	or, Cj - Ci = k
	or, Ci = Cj - k

	Hence, maintain a map<Ci,index of first occuence of Ci>
	For every j, we try to search for i = Cj-k
	If we are sucessful, we consider it as a possible length.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll longest_subrray_of_sum_k(ll A[],ll n,ll k){

	ll i,current_length,max_length,cum_sum;

	unordered_map<ll,ll> M;
	//Key:cum_sum value  Value:Index of 1st occuerence of cum_sum value

	cum_sum = 0;
	M[0] = -1;

	max_length = 0;
	for(i=0 ; i<n ; i++){

		cum_sum += A[i];

		// Searching for (cum_sum - k)
		if(M.find(cum_sum - k) != M.end()){
			current_length = (i - M[cum_sum - k]);
			max_length = max(max_length,current_length);
		}

		// Inserting cum_sum, if not present already
		if(M.find(cum_sum) == M.end())
			M[cum_sum] = i;		
	}

	return max_length;
}


void run_case(){

	ll i,n,k,ans;

    cin>>n>>k;	// k = 3     
    ll A[n];    // 1 -1 5 -2 3
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	ans = longest_subrray_of_sum_k(A,n,k);
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