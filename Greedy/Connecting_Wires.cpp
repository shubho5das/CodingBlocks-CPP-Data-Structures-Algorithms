/*
Problem:
We have n white dots and n black dots, equally spaced in a line.
Calculate the min length of wire required to connect each white 
dot with a black dot.


My Greedy Strategy:
Connect each black/white dot with nearest white/black dot
(simple intuition - first thing that would pop in anyone's mind)


Apporach:

- Iterate through the n points in left-to-right direction
- If we encounter white dot, connect with nearest black dot in 
right, and if we encounter black dot, connect it with nearest 
white dot. 
Total Length += (Length of the connection)
- Ans = Total Length

#Aliter Easier Implementaion:
(Prateek Bhaiya's style <3!)
- Store positions of black dots in array B[]
- Store positions of while dots in array W[]
- Iterate and compute abs(B[i]-W[i]), and increment it to total_len
- Ans = total_len.


Time Complexity = O(n)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll find_length(string S){

	ll N,i,total_length;

	N = S.length();

	vector<ll> black;
	vector<ll> white;
	black.reserve(N/2);
	white.reserve(N/2);
	
	for(i=0 ; i<N ; i++){
		if(S[i] == 'W')
			black.push_back(i);
		else
			white.push_back(i);
	}

	total_length = 0;
	for(i=0 ; i<N/2 ; i++){
		total_length += abs(black[i] - white[i]);
	}
	
	return total_length;
}

void run_case(){

	ll n;

	cin>>n;   // n = 3

	string S;
	cin>>S;	  // "WBWWBB"

	cout<<find_length(S)<<"\n";
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