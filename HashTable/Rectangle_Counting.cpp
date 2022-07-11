/* 
Problem:
Given N cartesian points, find the number of axis parallel
rectangles that can be formed by them

s
Time Complexity = O(n^2 * logn)
( Iteration for pair of pts : O(n^2)
  Lookup					: O(logn)	 )
[brute Force Implmentation, using Hashmaps]


*Imp NOTE*
-We are using set and not unordered_set/unordered_map,
because we want to store custom objects in our container.
-Whenever we want to store custom onjects, we must use set/map 
with a comparator class too. (just like in Priority Q's)


Approach:

- On drawing a 2-D Cartesian Plane on paper,
we clearly observe that 4 points P,Q,R,S follow the above property
if they are in the form:
	P(x1,y1),Q(x2,y2),R(x1,y2),S(x2,y1)
	where P and Q are diagnally opposite

- Hence, for every pair of points P(x1,y1) and Q(x2,y2),
	we check if (x1,y2) and (x2,y1) also exist.
	(This can be easily done using freq hashmaps)
If yes, count += 1

- On iterating over every pair of pts, we would first pick
P(x1,y1),Q(x2,y2) as pair and later R(x1,y2),S(x2,y1)
Thus, we would end up counting the same rectangle twice.
Hence, count /= 2.

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

class point{
public:
	ll x;
	ll y;

	// Constructor
	point(ll a,ll b){
		x = a;
		y = b;
	}
};

class point_compare{
public:
	bool operator()(point a,point b){
		if(a.x == b.x)
			return(a.y < b.y);
		return (a.x < b.x);
	}
};

ll count_rectangles(vector<pair<ll,ll>> V){

	ll n,i,j,count;

	n = V.size();

	set<point,point_compare> P;
	for(i=0 ; i<n ; i++){
		point a(V[i].first,V[i].second);
		P.insert(a);
	}

	count = 0;
	for(i=0 ; i<=(n-2) ; i++){
		for(j=(i+1) ; j<=(n-1) ; j++){
			
			point p1(V[i].first,V[i].second);
			point p2(V[j].first,V[j].second);

			// Special Case: Points p1 and p2 are collinear 
			if(p1.y == p2.y || p1.x == p2.x)
				continue;
			
			point p3(p1.x,p2.y);
			point p4(p2.x,p1.y);

			if( (P.find(p3) != P.end()) && (P.find(p4) != P.end()) )
				count += 1;
		}
	}

	count /= 2;
	return count;
}


void run_case(){

	vector<pair<ll,ll>> V{
		{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 1}, {2, 0}, {3, 1},
		{3, 0}
	};

	cout<<count_rectangles(V);
   
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