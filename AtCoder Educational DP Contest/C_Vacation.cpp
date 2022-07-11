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

ll A[N_max+5];
ll B[N_max+5];
ll C[N_max+5];

ll dp[N_max+5][3];

ll find_max_happiness(ll A[],ll B[],ll C[],ll n){

    ll i,j,ans;

    for(i=0 ; i<=n ; i++){
        for(j=0 ; j<=2 ; j++)
            dp[i][j] = 0;
    }

    // Base Case

    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];

    // General Case

    for(i=1 ; i<=(n-1) ; i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + A[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + B[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + C[i];
    }

    ans = max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    return ans;
}

void run_case(){

    ll n,i;

    cin>>n;

    for(i=0 ; i<n ; i++){
        cin>>A[i]>>B[i]>>C[i];
    }

    cout<<find_max_happiness(A,B,C,n)<<"\n";

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