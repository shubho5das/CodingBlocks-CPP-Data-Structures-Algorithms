#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

ll largest_unique_length(string S){

	ll n,i,window_length,max_length,last_occ;

	ll last_visited_index[256] = {-1};
	n = S.length();

	// Encounteriing the first character
	last_visited_index[(ll)(S[0])] = 0;
	window_length = 1;
	// Encountering the remaining characters
	max_length = 1;
	for(i=1 ; i<n ; i++){

		last_occ = last_visited_index[(ll)(S[i])]; 

		if( (last_occ == -1) || (last_occ < (i - window_length)) ){
			last_visited_index[(ll)(S[i])] = i;
			window_length += 1;
		}
		else{
			last_visited_index[(ll)(S[i])] = i;
			window_length = (i - last_occ);
		}

		if(window_length > max_length)
			max_length = window_length;
	}

	return(max_length);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	

    ll n,ans;

    string S;
    cin>>S;
    ans = largest_unique_length(S);
    cout<<ans<<"\n";

    return 0;
}



