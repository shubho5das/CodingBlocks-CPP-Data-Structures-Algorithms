// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

const ll N_max = 1e5;

ll height[N_max+5];
ll dp[N_max+5];

ll find_min_cost(ll height[],ll n,ll k){

    ll i,j;

    memset(dp,-1,sizeof(ll) * (n+1));

    // Base Case

    dp[0] = 0;
    
    for(i=1 ; i<=(k-1) ; i++){
        dp[i] = LLONG_MAX;
        for(j=0 ; j<i ; j++){
            dp[i] = min(dp[i], dp[j] + abs(height[i] - height[j]));
        }
    }

    // General Case

    for(i=k ; i<=(n-1) ; i++){

        dp[i] = LLONG_MAX;

        for(j=1 ; j<=k ; j++){
            dp[i] = min(dp[i] , dp[i-j] + abs(height[i] - height[i-j]));
        }
    }

    return dp[n-1];

}

void run_case(){
    
    ll n,k,i;

    cin>>n>>k;

    for(i=0 ; i<n ; i++){
        cin>>height[i];
    }
    
    cout<<find_min_cost(height,n,k)<<"\n";

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