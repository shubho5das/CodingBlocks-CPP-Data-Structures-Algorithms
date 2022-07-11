#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

const ll N_max = 1e3;

ll dp[N_max+5][N_max+5];

string A[N_max+5];

ll count_ways(string A[],ll R,ll C){

    ll i,j;

    for(i=0 ; i<=R ; i++){
        for(j=0 ; j<=C ; j++)
            dp[i][j] = -1;
    }

    // Base Case
    for(i=0 ; i<R ; i++){
        for(j=0 ; j<C ; j++){
            if(A[i][j] == '#')
                dp[i][j] = 0;
        }
    }

    dp[0][0] = 1; // (0,0) is never blocked - mention in Prob

    for(j=1 ; j<C && A[0][j] != '#' ; j++)
        dp[0][j] = 1;
    for( ; j<C ; j++)
        dp[0][j] = 0;

    for(i=1 ; i<R && A[i][0] != '#' ; i++)
        dp[i][0] = 1;
    for( ; i<R ; i++)
        dp[i][0] = 0;

    // General Case
    for(i=1 ; i<R ; i++){
        for(j=0 ; j<C ; j++){
            
            if(dp[i][j] == -1){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }

    return dp[R-1][C-1];

}


void run_case(){
    
    ll R,C,i;

    cin>>R>>C;

    for(i=0 ; i<R ; i++)
        cin>>A[i];

    cout<<count_ways(A,R,C)<<"\n";

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