/*
Problem:
A religious king wants to build the largest temple in his kingdom . 
To build the largest temple he needs to find the area of the largest 
suitable land . Given co-ordinates which denotes rivers flowing through
the point horizontally as well as vertically, find the largest area 
possible to make the grand temple.
Consider 2 rivers flowing across x-axis as well as y-axis. The temple 
must be enclosed by rivers on all 4 sides.


Key Observation/Approach:

- This Problem is exactly the same as "Kingdom Defence (SPOJ)" Problem
- The only tricky thing to handle is,
  since the "area must be enclosed by rivers on all 4 sides", we don't
  need to insert -1th and nth coordinate to the X and Y Vectors.

Time Complexity = O(n*logn), where n is no. of towers
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

void run_case(){

	ll w,h,n,i,j,x,y,row,col;
	ll x_max,y_max,max_area;

	cin>>n;

	vector<ll> X;
	vector<ll> Y;

	for(i=0 ; i<n ; i++){

		cin>>x>>y;
		x -= 1;
		y -= 1;
		row = y;
		col = x;
		X.push_back(col);
		Y.push_back(row);
	}
	
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	x_max = LLONG_MIN;
	y_max = LLONG_MIN;
	for(i=0 ; i<=(X.size()-2) ; i++){
		x_max = max(x_max,(X[i+1] - X[i] - 1));
	}
	for(i=0 ; i<=(Y.size()-2) ; i++){
		y_max = max(y_max,(Y[i+1] - Y[i] - 1));
	}

	max_area = x_max * y_max;
	cout<<max_area<<"\n";
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
