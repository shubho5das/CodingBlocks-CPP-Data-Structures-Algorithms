#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll dp[1005][1005];

ll find_number_of_ways(ll R,ll C,vector<pair<ll,ll>> blockage){

    ll i,j,r,c;

    memset(dp,-1,sizeof(dp));

    // Base Case

    for(i=0 ; i<blockage.size() ; i++){
        
        r = blockage[i].first;
        c = blockage[i].second;

        dp[r][c] = 0;
    }

    if(dp[0][0] == -1)
        dp[0][0] = 1;

    for(j=1 ; j<C ; j++){
        
        if(dp[0][j] == 0)
            continue;

        if(dp[0][j-1] == 0)
            dp[0][j] = 0;
        else
            dp[0][j] = 1;
    }

    for(i=1 ; i<R ; i++){

        if(dp[i][0] == 0)
            continue;

        if(dp[i-1][0] == 0)
            dp[i][0] = 0;
        else
            dp[i][0] = 1;
    }
    
    // General Case

    for(i=1 ; i<R ; i++){
        for(j=1 ; j<C ; j++){

            if(dp[i][j] == -1){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
    }

    dp[R-1][C-1] %= mod;
    return dp[R-1][C-1];
}

int main(){

    ll R,C,p,i,r,c;

    cin>>R>>C>>p;

    vector<pair<ll,ll>> blockage;
    for(i=0 ; i<p ; i++){
        cin>>r>>c;
        r -= 1;
        c -= 1;
        blockage.push_back({r,c});
    }

    cout<<find_number_of_ways(R,C,blockage)<<"\n";

    return 0;
}
