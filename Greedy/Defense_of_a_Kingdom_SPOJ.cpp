/*
Problem:
There's a rectangular grid having n towers. The tower defends all the
cells in the same row and the same column. No two towers share a row 
or a column. 
Determine the area of the largest rectangle that is not defended by
any tower.

Greedy Strategy:
Area of Largest Rectangle = del(X max) * del(Y max)

Apporach:
See Diary II (Pg 210)

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

	cin>>w>>h>>n;

	vector<ll> X;
	X.push_back(-1);
	vector<ll> Y;
	Y.push_back(-1);

	for(i=0 ; i<n ; i++){

		cin>>x>>y;
		x -= 1;
		y -= 1;
		row = y;
		col = x;
		X.push_back(col);
		Y.push_back(row);
	}
	X.push_back(w);
	Y.push_back(h);

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
    cin>>T;
    while(T--)
        run_case();

    return 0;
}
