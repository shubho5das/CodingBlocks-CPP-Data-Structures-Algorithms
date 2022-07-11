#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void number_to_spelling(ll N)
{	
	ll rem;
	string word[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	// Base Case
	if(N==0)
		return;

	// Recursive Case

	// First, print the spellings of 204
	number_to_spelling(N/10);

	//Then, print the spelling of the last digit- 8
	cout<<word[N%10]<<" ";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	ll N;

	cin>>N;

	number_to_spelling(N);
	cout<<"\n";

	return 0;
}