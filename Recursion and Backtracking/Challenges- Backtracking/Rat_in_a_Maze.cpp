#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

bool rat_in_a_maze(char A[][1002],ll soln[][1002],ll i,ll j,ll N,ll M,ll &count){

	ll k,l;
	bool right_success,down_success;

	// Base Case
	if(i==N && j==M ){
		soln[i][j] = 1;

		for(k=0 ; k<=N ; k++){
			for(l=0 ; l<=M ; l++)
				cout<<soln[k][l]<<" ";
			cout<<"\n";
		}

		count += 1;
		return true;
	}

	if(count ==1){
		return false;
	}
	// Special Case- rat tryna move out of maze
	if(i>N || j>M)
		return false;
	// Speical Case- rat encounters blockage
	if(A[i][j] == 'X')
		return false;

	// Recursive Case
	soln[i][j] = 1;
	// Case 1: Moving right
	right_success = rat_in_a_maze(A,soln,i,j+1,N,M,count);
	// Case 2: Moving down
	down_success = rat_in_a_maze(A,soln,i+1,j,N,M,count);
	// Backtraking - undoing our move of making soln[] cell 1, in bottom-up direction(after hittng base case)
	soln[i][j] = 0;

	if(right_success || down_success)
		return true;
	return false;
}

char A[1002][1002];
ll soln[1002][1002] = {0};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N,M,i,j,count;
	bool ans;
	
	cin>>N>>M;
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<M ; j++)
			cin>>A[i][j];
	}
	count = 0;
	ans = rat_in_a_maze(A,soln,0,0,N-1,M-1,count);

	if(ans == false)
		cout<<"-1\n";

	return 0;
}


