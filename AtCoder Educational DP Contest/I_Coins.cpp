#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(15)<<x<<"\n";

const ll N_max = 3e3;

ld dp[N_max+5][N_max+5];

ld P[N_max+5];

ld find_probability(ld P[],ll n){

    ll i,j;

    for(i=0 ; i<=n ; i++){
        for(j=0 ; j<=n ; j++)
            dp[i][j] = -1.0;
    }

    // Base Case

    dp[0][0] = 1.0;

    dp[0][1] = P[0];
    for(j=2 ; j<=n ; j++)
        dp[0][j] = 0.0;

    for(i=1 ; i<n ; i++)
        dp[i][0] = 1.0;

    // General Case
    for(i=1 ; i<n ; i++){
        for(j=1 ; j<=n ; j++){
            dp[i][j] = (P[i] * dp[i-1][j-1]) + ((1.0 - P[i]) * dp[i-1][j]);
        }
    }

    // For n(H) > n(T), n(H) >= (n+1)/2. Thus, j = (n+1)/2
    return dp[n-1][(n+1)/2]; 

}



void run_case(){

    ll n,i;
    ld ans;

    cin>>n;

    for(i=0 ; i<n ; i++){
        cin>>P[i];
    }

    ans = find_probability(P,n);
    prDouble(ans);
    
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