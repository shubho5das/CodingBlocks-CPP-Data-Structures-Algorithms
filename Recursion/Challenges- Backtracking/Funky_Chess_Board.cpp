#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void solve_funky(ll i,ll j,ll visited,ll &max_visited,ll board[10][10]){

	//Base Case
	if( ((i<0 || i>=10)||(j<0 || j>=10)) || (board[i][j]==0) ){
		//cout<<"Hello\n"; // debugging
		return;
	}

	// Recursive Case
	board[i][j] = 0;
	// Checking for maxima in top-down direction Hence, code written before recursive call
	max_visited = max(max_visited,visited+1);
	//Trying all possoible 8 cases for the knight
    solve_funky(i-1,j-2,visited+1,max_visited,board);
    solve_funky(i-2,j-1,visited+1,max_visited,board);
    solve_funky(i+1,j-2,visited+1,max_visited,board);
    solve_funky(i+2,j-1,visited+1,max_visited,board);
    solve_funky(i-1,j+2,visited+1,max_visited,board);
    solve_funky(i-2,j+1,visited+1,max_visited,board);
    solve_funky(i+1,j+2,visited+1,max_visited,board);
    solve_funky(i+2,j+1,visited+1,max_visited,board);
	//Backtracking- undoing our action of visiting a cell in bottom-up direction
	board[i][j] = 1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,total,visited,max_visited,unvisited,i,j;
	ll board[10][10] = {0};

	cin>>n;
	// If board has cell=1, only that cell can be visited.
	// Cell=0 cannot be visited
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++)
			cin>>board[i][j];  
	}
	
	total = 0;
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			if(board[i][j] == 1)
				total += 1;
		}
	}

	max_visited = 0;
	solve_funky(0,0,0,max_visited,board);
	unvisited = (total - max_visited);
	cout<<unvisited<<"\n"; 
	
	return 0;
}
