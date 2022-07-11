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

ll dp[N_max+5][N_max][2];

ll A[N_max+5];

ll find_X(ll A[],ll n,ll i,ll j,ll turn,ll dp[N_max+5][N_max][2]){
    // Top Down Approach

    ll ans,op1,op2;

    // Base Case
    if(i > j)
        return 0;

    // Recursive Case

    // Look Up
    if(dp[i][j][turn] != -1)
        return dp[i][j][turn];

    if(turn == 0){
        // Player1's Turn. He tries to maximise X value
        op1 = A[i] + find_X(A,n,i+1,j,1LL,dp);
        op2 = A[j] + find_X(A,n,i,j-1,1LL,dp);
        ans = max(op1,op2);
    }
    else if(turn == 1){
        // Player 2's Turn. He tries to minimize X value
        op1 = find_X(A,n,i+1,j,0LL,dp);
        op2 = find_X(A,n,i,j-1,0LL,dp);
        ans = min(op1,op2);
    }

    dp[i][j][turn] = ans;
    return ans;
}

void run_case(){

    ll n,sum,i,j,turn,X,Y;

    cin>>n;

    sum = 0;
    for(i=0 ; i<n ; i++){
        cin>>A[i];
        sum += A[i];
    }

    for(i=0 ; i<=n ; i++){
        for(j=0 ; j<=n ; j++){
            for(turn=0 ; turn<2 ; turn++){
                dp[i][j][turn] = -1;
            }
        }
    }

    // Finding X
    i = 0, j = (n-1); 
    turn = 0; // Player1 starts the game
    X = find_X(A,n,i,j,turn,dp);

    Y = sum - X;

    cout<<(X - Y)<<"\n";

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