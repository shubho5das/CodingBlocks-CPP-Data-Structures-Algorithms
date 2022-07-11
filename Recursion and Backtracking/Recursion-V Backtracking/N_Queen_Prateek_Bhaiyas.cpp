#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

bool is_safe(ll board[][10],ll i ,ll j,ll N)
{
	ll row,col,x,y;

	// Checking upward direction
	for(row=0 ; row<i ; row++)
	{
		if(board[row][j] == 1)
			return false;
	}

	x = i;
	y = j;
	while(x>=0 && y>=0)
	{
		if(board[x][y] == 1)
			return false;

		x--;
		y--;
	}

	
	x = i;
	y = j;
	while(x>=0 && y<N)
	{
		if(board[x][y]==1)
			return false;

		x--;
		y++;
	}

	return true;

}

bool solve_N_Queen(ll board[][10] , ll i ,ll N)
{
	ll j,k,l;
	bool next_queen_rakh_paye;
	ll flag;

	// Base Case
	if(i==N)
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

		return true;
	}

	// Recursive Case

	flag = 0;
	for(j=0 ; j<N ; j++)
	{
		if(is_safe(board,i,j,N) == 1)
		{
			board[i][j] = 1;
			
			next_queen_rakh_paye = solve_N_Queen(board,i+1,N);

			if(next_queen_rakh_paye == 1)
				return true;
			else
			{
				// Backtracking
				board[i][j] = 0;
			}
		}
	}
	return false;
}

int main()
{
	ll N;
	ll board[10][10] = {0};

	cin>>N;
	solve_N_Queen(board,0,N);

	return 0;
}
