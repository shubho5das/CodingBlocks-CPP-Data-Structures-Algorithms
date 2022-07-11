#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void move(ll N,char src,char dest,char aux)
{
	// Base Case
	if(N==0)
		return;

	// Recursive Case
	move(N-1,src,aux,dest);
	cout<<"Shift disk "<<N<<" from "<<src<<" to "<<dest<<"\n";
	move(N-1,aux,dest,src);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N;

	cin>>N;
	move(N,'A','C','B');

	return 0;
}