/*
Problem:
There are n circles arranged on x-y plane. All of them have their 
centers on x-axis. You have to remove some of them, such that no two 
circles are overlapping after that. Find the minimum number of 
circles that need to be removed.

Key Observation/Insight:

This Problem is equivalent to "Activity Selection Problem"
ans = n - (activites selected).
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

class circle{
public:
	ll l;
	ll r;

	// Constructor
	circle(ll a, ll b){
		l = a;
		r = b;
	}
};

bool circle_compare(circle a,circle b){
	if(a.r == b.r)
		return(a.l < b.l);

	return(a.r < b.r);
}

void run_case(){

	ll n,c,r,i,selected,x;

	vector<circle> V;

	cin>>n;
	for(i=0 ; i<n ; i++){
		cin>>c>>r;
		circle cir(c-r,c+r);
		V.push_back(cir);
	}
	sort(V.begin(),V.end(),circle_compare);

	selected = 0;
	x = LLONG_MIN;
	for(i=0 ; i<n ; i++){
		
		if(V[i].l >= x){
			selected += 1;
			x = V[i].r;
		}	
	}

	cout<<(n - selected)<<"\n";
	

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