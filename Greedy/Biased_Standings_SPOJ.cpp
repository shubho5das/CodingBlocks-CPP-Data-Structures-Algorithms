/*
Problem:
Given team names and their preferred placements find one ranklist 
with the minimal possible badness.
(Our goal is to make everyone as happy as possible)

"Badness" of a ranklist  is defined as sum of differeces between 
a team's preferred rank and their actual rank.

Problem Tags:
#greedy #sortings

Greedy Strategy:
"Assign a team a rank that is closest available."

Approach:
-Sort the preferred ranks,A[] of all teams in increasing order
- Badness += abs(pos[i] - (i+1));
- Ans = badness.

Time Complexity:

-Using in-built sort(), time complexity = O(nlogn).
-However, we can optmise it further to O(n), using couting sort 
technque.

[NOTE: Whenever, we need to sort ranks, which lie in range [1,n] or 
similar situations, counting sort can be used.
This enables us to reduce complexity to O(n).]

[Refer: https://www.geeksforgeeks.org/counting-sort/ (blog)
    	 https://www.youtube.com/watch?v=7zuGmKfUt7s (video)  
	   											if needed! ]

[Counting Sort is nothing but maintaing a freq[] array, and then
iterating freq[] array from left-to-right.]
"So easy, LOL!(sigh) :) )

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

class team{
public:
	string name;
	ll preferred_rank;

	// Constructor
	team(string S,ll x){
		name = S;
		preferred_rank = x;
	}
};

bool team_compare(team a,team b){
	return(a.preferred_rank < b.preferred_rank);
}

void run_case(){

	ll n,i,badness;

	cin>>n;
	vector<team> V;
	V.reserve(n);

	for(i=0 ; i<n ; i++){
		string S;
		ll x;
		cin>>S>>x;
		team t(S,x);
		V.push_back(t);
	}

	// Prateek Bhaiya's appraoch: O(n^2) in worst case
	// (1,1,1,1,1) or (5,5,5,5,5). Very bad! ;)

	sort(V.begin(),V.end(),team_compare);

	badness = 0;
	for(i=0 ; i<n ; i++){
		badness += abs((i+1) - V[i].preferred_rank);
		// badness += abs(actual rank - preferred rank)
	}

	cout<<badness<<"\n";
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