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

ll find_min_cost(ll height[],ll n){

    ll i,op1,op2;

    memset(dp,-1,sizeof(ll)*(n+1));

    // Base Case
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    // General Case
    for(i=2 ; i<=(n-1) ; i++){

        op1 = dp[i-1] + abs(height[i] - height[i-1]);
        op2 = dp[i-2] + abs(height[i] - height[i-2]);

        dp[i] = min(op1,op2);
    }

    return dp[n-1];

}

void run_case(){
    
    ll n,i;

    cin>>n;
    for(i=0 ; i<n ; i++){
        cin>>height[i];
    }
    
    cout<<find_min_cost(height,n)<<"\n";

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