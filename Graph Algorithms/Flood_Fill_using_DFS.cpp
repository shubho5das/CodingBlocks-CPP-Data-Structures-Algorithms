/*
Input:

15 50

..................................................
..................................................
..............################....................
..............#..............#....................
..............#..............#....................
..............#..............#....................
..............#..............#....................
..............#..............#....................
..............#..............#....................
..............################....................
..................................................
..................................................
..................................................
..................................................
..................................................
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

void print_grid(char grid[][100],ll r,ll c){

	ll i,j;

	for(i=0 ; i<r ; i++){
		for(j=0 ; j<c ; j++)
			cout<<grid[i][j];
		cout<<"\n";
	}
}

// ch    -> Character to be replaced
// color -> Charected to be filled in 
void flood_fill(char grid[][100],ll r,ll c,ll i,ll j,char ch,char color){

	// Base Case
	if(i<0 || j<0 || i>=r || j>=c){
		// Out of grid
		return;
	}
	if(grid[i][j] != ch){
		// Boundary Reached
		return;	
	}

	// Recursive Case

	grid[i][j] = color;

	flood_fill(grid,r,c,i+1,j,ch,color); // D
	flood_fill(grid,r,c,i,j-1,ch,color); // L
	flood_fill(grid,r,c,i-1,j,ch,color); // U
	flood_fill(grid,r,c,i,j+1,ch,color); // R

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r,c,i,j;

    char input[100][100];

    cin>>r>>c;

    for(i=0 ; i<r ; i++){
    	for(j=0 ; j<c ; j++)
    		cin>>input[i][j];
    }

    // Before Flood Fill
    print_grid(input,r,c);
    cout<<"\n";

    flood_fill(input,r,c,5,20,'.','r');

    // After Flood Fill
    print_grid(input,r,c);
    cout<<"\n";

    return 0;
}