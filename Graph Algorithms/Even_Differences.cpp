// KEEP CALM and Enjoy the Problem B-)

// CC January Cookoff 2021(Div3)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

void run_case(){

    ll n,i,count_even,count_odd;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++){
        cin>>A[i];
    }

    count_odd = 0;
    for(i=0 ; i<n ; i++){
        if(A[i]%2 == 0)
            count_odd += 1; 
    }
    

    count_even = 0;
    for(i=0 ; i<n ; i++){
        if(A[i]%2 != 0)
            count_even += 1;
    }
    
    cout<<min(count_odd,count_even)<<"\n";
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    cin>>T;
    while(T--)
        run_case();

    return 0;
}