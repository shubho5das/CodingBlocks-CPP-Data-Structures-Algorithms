/*
Problem:
You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a
single person, assuming that a person can only work on a single
activity at a time.


My Greedy Strategy:
(figured out on my own B-) )

Keep choosing activity that starts after time t, and ends earliest
	ie, choose activity : start>t and end is minimum.

Prateek Bhaiya: "If an activity finishes early, it allows us to 
perform more activities later."


My Approach: 

- Sort all activities in increasing order of their end times
- Iterate over the activites, keep choosing the optimal activity
(as described above) and increment count += 1
- Ans = count


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

class activity{
public:
	ll start;
	ll end;

	// Constructor
	activity(ll a,ll b){
		start = a;
		end = b;
	}
};

bool activity_compare(activity a,activity b){
	
	if(a.end == b.end)
		return(a.start < b.start);

	return(a.end < b.end);
}

ll count_activity(vector<activity> V){

	ll count,i,n,t;

	n = V.size();
	sort(V.begin(),V.end(),activity_compare);

	count = 0;
	t = 0;
	for(i=0 ; i<n ; i++){

		if(V[i].start >= t){
			count += 1;
			t = V[i].end;
		}
	}

	return count;
}

void run_case(){

	ll n,s,e,i;

	cin>>n;
	vector<activity> V;
	for(i=0 ; i<n ; i++){
		cin>>s>>e;;
		activity a(s,e);
		V.push_back(a);
	}

	cout<<count_activity(V)<<"\n";

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