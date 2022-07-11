#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

bool can_place(ll A[][9],ll x,ll y,ll N,ll digit)
{
	ll s_x,s_y,i,j;

	// Checking the row
	for(i=0 ; i<N ; i++)
	{
		if(A[i][y] == digit)
			return false;
	}

	// Checking the coloumn
	for(j=0 ; j<N ; j++)
	{
		if(A[x][j] == digit)
			return false;
	}

	// Checking the sub-matrix
	s_x = (x/3) * 3;
	s_y = (y/3) * 3;

	for(i=s_x ; i<(s_x + 3) ; i++)
	{
		for(j=s_y ; j<(s_y + 3) ; j++)
		{
			if(A[i][j] == digit)
				return false;

		}
	}

	return true;
}

bool solve_sudoku(ll A[][9],ll i,ll j,ll N){
	ll k,l,digit;
	bool can_we_fill_next;

	// Base Case
	if( i == N)
	{
		for(k=0 ; k<N ; k++)
		{
			for(l=0 ; l<N ; l++)
				cout<<A[k][l]<<" ";
			cout<<"\n";
		}
		return true;
	}
	// Special Case 1: End of Row
	if(j == N)
		return( solve_sudoku(A,i+1,0,N) ); 
	// Special Case 2: Prefilled cell encountered - skip it!
	if( A[i][j] != 0 )
		return( solve_sudoku(A,i,j+1,N) );

	// Recursive Case
	for( digit=1 ; digit<=9 ; digit++ )
	{
		if( can_place(A,i,j,N,digit) == 1 )
		{
			// Assume the digit filled is correct
			A[i][j] = digit;

			can_we_fill_next = solve_sudoku(A,i,j+1,N);

			if(can_we_fill_next == true)
				return true;
		}
	}
	// Backtracking 
	A[i][j] = 0;
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll A[9][9];
	ll i,j,N;

	cin>>N;
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++)
			cin>>A[i][j];
	}
			   
	solve_sudoku(A,0,0,N);

	return 0;
}
