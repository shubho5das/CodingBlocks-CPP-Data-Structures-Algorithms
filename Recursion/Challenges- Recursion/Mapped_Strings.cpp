#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

char alphabet[] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void generate_strings(string &in,char out[],ll i,ll j,vector<string> &V)
{	
	ll curr_digit,next_digit,num;

	// Base Case
	if( in[i] == '\0' )
	{
		out[j] = '\0';
		V.push_back(out);
		return;
	}

	// Recursive Case

	// Case 1: Including a single digit
	if( in[i] != '0')
	{
		out[j] = alphabet[(ll)(in[i] - '0')];
		generate_strings(in,out,i+1,j+1,V);
	}
	// Case 2: Including 2-digits
	if( in[i+1] != '\0')
	{
		curr_digit = (ll)(in[i] - '0');
		next_digit = (ll)(in[i+1] - '0');

		if( (curr_digit==1) || ( curr_digit==2 && next_digit <= 6 ) )
		{
			num = (ll)(10 * curr_digit + next_digit );
			out[j] = alphabet[num];
			generate_strings(in,out,i+2,j+1,V);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll i;
	string in;
	char out[10];

	cin>>in;

	vector<string> V;

	generate_strings(in,out,0,0,V);

	sort(V.begin(),V.end());
	for(i=0 ; i<V.size() ; i++)
		cout<<V[i]<<"\n";

	return 0;
}