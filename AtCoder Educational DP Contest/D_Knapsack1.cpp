// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

const ll N_max = 100;
const ll W_max = 1e5;

ll dp[N_max+5][W_max+5];

ll W[N_max+5]; // weight
ll V[N_max+5]; // value

ll find_max_value(ll n,ll C){

    ll i,j,op1,op2;

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<=C ; j++){
            dp[i][j] = -1;
        }
    }

    // Base Case

    for(j=0 ; j<=C ; j++){
        if(j < W[0])
            dp[0][j] = 0;
        else
            dp[0][j] = V[0];
    }

    // General Case
    for(i=1 ; i<=(n-1) ; i++){

        for(j=0 ; j<=C ; j++){

            op1 = -inf,op2 = -inf;

            if(j >= W[i])
                op1 = V[i] + dp[i-1][j-W[i]];

            op2 = dp[i-1][j];

            dp[i][j] = max(op1,op2);
        }
    }

    return dp[n-1][C];
}

void run_case(){

    ll n,C,i;

    cin>>n>>C;

    for(i=0 ; i<n ; i++){
        cin>>W[i]>>V[i];
    }

    cout<<find_max_value(n,C);
    
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