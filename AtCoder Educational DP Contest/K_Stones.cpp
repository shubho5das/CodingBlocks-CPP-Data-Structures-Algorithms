#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(15)<<x<<"\n";

const ll N_max = 1e2;
const ll K_max = 1e5;

ll dp[K_max+5];

ll A[N_max+5];

void determine_winner(ll A[],ll n,ll k){

    ll i,j;

    memset(dp,-1,sizeof(ll)*(k+1));

    // Base Case
    dp[0] = 0;
    
    // General Case
    for(i=0 ; i<=k ; i++){

        dp[i] = 0;
        for(j=0 ; j<n ; j++){
            if( (i-A[j]) >= 0  && dp[i-A[j]] == 0){
                // If dp[i - A[j]] is a losing state, dp[i] is a winning state
                dp[i] = 1;
                break;
            }
        }
    }

    if(dp[k] == 1)
        cout<<"First\n";
    else
        cout<<"Second\n";

}

void run_case(){

    ll n,k,i;

    cin>>n>>k;

    for(i=0 ; i<n ; i++){
        cin>>A[i];
    }

    determine_winner(A,n,k);
    
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