/*
Problem: 
Given N points in a 2-D Cartesian Plane,
how many right-angled triangles are there such that perpenicular
or base is parallel to X or Y axis?

(Assumed there are no duplicate points
If duplicates exist, need to delete them first)

Time Complexity = O(n)


*My approach*:

- On drawing a 2-D Cartesian Plane on paper,
I clearly observe that 3 points P,Q,R follow the above property
if they are in the form:
	P(x,y),Q(x,_),R(_,y) 

- Thus,for P(x,y),
	tringles formed = C(n1-1,1) * C(n2-1,1) = (n1-1)*(n2-1)
		where,(n1-1) = no. of Q pts (points having same x as P) 
			  (n2-1) = no. of R pts (points having same y as P)
	count += triangles formed
	
- Finally, ans = count

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll count_right_triangles(ll X[],ll Y[],ll n){

	ll count,n1,n2,i;

	unordered_map<ll,ll> freq_X;
	unordered_map<ll,ll> freq_Y;

	for(i=0 ; i<n ; i++){
		freq_X[X[i]] += 1;
		freq_Y[Y[i]] += 1;
	}

	count = 0;
	for(i=0 ; i<n ; i++){
		n1 = freq_X[X[i]];
		n2 = freq_Y[Y[i]];

		count += (n1-1)*(n2-1); 
	}

	return count;
}

void run_case(){

	ll n,i;

	cin>>n;
	ll X[n];
	ll Y[n];
	for(i=0 ; i<n ; i++){
		cin>>X[i]>>Y[i];
	}
	// (1,2),(2,2),(3,2),(1,3),(1,4)
	// Ans = 4

	cout<<count_right_triangles(X,Y,n)<<"\n";
	
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
