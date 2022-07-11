#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

bool rat_in_maze(char maze[10][10],ll soln[][10],ll i,ll j,ll m,ll n)
{
	ll k,l;
	bool right_success,down_success;

	// Base Case

	// Destination reached
	if(i==m && j==n)
	{
		soln[m][n] = 1;
		for(k=0;k<=m;k++)
		{
			for(l=0;l<=n;l++)
				cout<<soln[k][l];
			cout<<"\n";
		}
		cout<<"\n";
		return true; // IMPORTANT- Missed it, initially!
	}

	// Going out of the grid
	if( i>m || j>n )
		return false;

	// Blockage encountered
	if(maze[i][j] == 'X')
		return false;

	// Recursive Case
 
	soln[i][j] = 1;

	// Case 1: Moving right
	right_success = rat_in_maze(maze,soln,i,j+1,m,n);
	// Case 2: Moving down
	down_success = rat_in_maze(maze,soln,i+1,j,m,n);

	// Backtracking - undoing our action of filling cell with 1 
	//( gets executed in bottom-up direction)
	soln[i][j] = 0;
	
	if(right_success || down_success)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll m,n;
	bool ans;

	char maze[10][10] = {"0000","00X0","000X","0X00"};
	ll soln[10][10] = {0};

	m = 4;
	n = 4;
	ans = rat_in_maze(maze,soln,0,0,m-1,n-1);

	if(ans == false)
		cout<<"Path does not exist";

	return 0;
}