// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

const ll N_max = 3000;

ll dp[N_max+5][N_max+5];

// Helper dp Function
ll find_LCS_length(string &S,string &T,ll i,ll j,ll dp[][N_max+5]){
    // Top Down Appoach

    ll op1,op2,ans;

    // Base Case
    if(i == S.length() || j == T.length() ){
        return 0;
    }

    // Recursive Case

    // Look Up
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(S[i] == T[j]){
        ans = 1 + find_LCS_length(S,T,i+1,j+1,dp);
    }
    else{
        op1 = find_LCS_length(S,T,i+1,j,dp);
        op2 = find_LCS_length(S,T,i,j+1,dp);

        ans = max(op1,op2);
    }

    dp[i][j] = ans;
    return ans;
}

string find_LCS_string(string &S,string &T){

    ll i,j,len,current_len;

    for(i=0 ; i<=S.length() ; i++){
        for(j=0 ; j<=T.length() ; j++)
            dp[i][j] = -1;
    }

    len = find_LCS_length(S,T,0LL,0LL,dp);

    string solution;

    i = 0, j = 0;
    current_len = 0;
    while(current_len < len){

        if(S[i] == T[j]){

            solution += S[i];

            i += 1;
            j += 1;
            current_len += 1;
        }
        else{

            if(dp[i+1][j] >= dp[i][j+1])
                i += 1;
            else
                j += 1;
        }
    }

    return solution;
}

void run_case(){

    string S,T;

    cin>>S;
    cin>>T;

    cout<<find_LCS_string(S,T)<<"\n";
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