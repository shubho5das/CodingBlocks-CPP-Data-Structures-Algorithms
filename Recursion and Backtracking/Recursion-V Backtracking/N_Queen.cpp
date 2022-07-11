#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

// is_safe() checks whether it is safe to place the queen in the given (x,y) coordinate
bool is_safe(ll board[][20],ll x,ll y,ll N)
{
	ll i,j,flag;

	flag = 1;

	// Checking in upward direction
	for( i=0 ; i<=x ; i++)
	{
		if(board[i][y] == 1)
		{
			flag = 0;
			break; 
		}
	}

	// Checking in upper left-diagonal direction
	i = x;
	j = y;
	while(i>=0 && j>=0)
	{
		if(board[i][j] == 1)
		{
			flag = 0;
			break;
		}

		i -= 1;
		j -= 1;
	}

	// Checking in upper right-diagonal direction
	i = x;
	j = y;
	while(i>=0 && j<=(N-1))
	{
		if(board[i][j] == 1)
		{
			flag = 0;
			break;
		}

		i -= 1;
		j += 1;
	}

	if(flag == 1)
		return true;
	else if( flag == 0)
		return false;

}

bool solve_N_queen( ll board[][20] , ll i , ll N )
{
	ll j,k,l,flag;
	bool next_queen_rakh_paye; // Alter variable name: "could_we_solve"

	// Base Case
	if(i == N)
	{
		for(k=0 ; k<N ; k++)
		{
			for(l=0 ; l<N ; l++)
			{
				if(board[k][l] == 1)
					cout<<"Q ";
				else
					cout<<"_ ";
			}
			cout<<"\n";
		}
		cout<<"\n";

		return true;
	}

	// Recursive Case
	flag = 0;

	for(j=0 ; j<N ; j++)
	{
		if(is_safe(board,i,j,N) == 1) 
		{
			board[i][j] = 1;
		

			next_queen_rakh_paye = solve_N_queen(board,i+1,N); // Recursive Call

			if(next_queen_rakh_paye)
			{
				flag = 1;
				return true;
			}
			else
			{
				// Backtracking
				board[i][j] = 0;
			}
		}
  	}
	
	if(flag == 0)
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N;
	bool ans;
	ll board[20][20] = {0};

	cin>>N;
	ans = solve_N_queen(board,0,N); 

	if(ans == false)
		cout<<"A possible solution DNE\n";

	return 0;
}
