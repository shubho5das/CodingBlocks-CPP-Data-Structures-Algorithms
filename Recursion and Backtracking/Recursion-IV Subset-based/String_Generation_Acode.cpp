#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

char alphabet[] = {'a','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void generate_strings(string &in,char out[],ll i,ll j)
{
	ll curr_digit,next_digit,num;

	// Base Case
	if(in[i]=='\0')
	{
		out[j] = '\0';
		cout<<out<<"\n";
		return;
	}

	// Recursive Case

	// Case 1: Including a single character
	if(in[i]!='0')
	{	
		out[j] = alphabet[(ll)(in[i] - '0')];
		generate_strings(in,out,i+1,j+1);
	}

	// Case 2: Including double character
	if(in[i+1] != '\0')
	{
		curr_digit = (ll)(in[i] - '0');
		next_digit = (ll)(in[i+1] - '0');

		if( (curr_digit == 1) || (curr_digit == 2 && next_digit <=6) )
		{
			num = (10*curr_digit + next_digit);
			out[j] = alphabet[num];

			generate_strings(in,out,i+2,j+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string input;
	char output[1000];

	cin>>input;
	generate_strings(input,output,0,0);

	return 0;
}