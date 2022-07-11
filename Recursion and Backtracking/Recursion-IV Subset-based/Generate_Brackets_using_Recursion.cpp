#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void generate_brackets(char out[],ll N,ll i,ll count_open,ll count_close)
{
	// Base Case
	if(i == 2*N)
	{
		out[i] = '\0'; // Converting character array, out[] into a valid string
		cout<<out<<"\n";
		return;
	}

	// Recursive Case

	// Case 1: Fill with '('
	if(count_open < N)
	{
		out[i] = '(';
		generate_brackets(out,N,i+1,count_open+1,count_close);
	}
	if(count_close < count_open)
	{
		out[i] = ')'; // Overwriting out[i] = '(' with out[i] = ')'
		generate_brackets(out,N,i+1,count_open,count_close+1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N;
	
	cin>>N;
	
	char output[1000];
	ll index = 0;

	generate_brackets(output,N,0,0,0);

	return 0;
}

