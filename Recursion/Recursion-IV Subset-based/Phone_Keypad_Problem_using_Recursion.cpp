#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKl","MNO","PQRS","TUV","WXYZ"};

void generate_names(string &in,char out[],ll i,ll j)
{
	ll k;
	ll digit;

	// Base Case

	if(in[i]=='\0')
	{
		out[j] = '\0';
		cout<<out<<"\n";
		return;
	}

	// Recursive Case

	//Special Case
	if(in[i]=='0'|| in[i]=='1') 
	{
		generate_names(in,out,i+1,j); 
		// We simply move to the next character of the input array
	}

	// Converting charcter '2','3'.. to integers 2,3,...
	digit = (ll)(in[i] - '0'); 
	 
	// 3 Choices 
	for(k=0 ; k < keypad[digit].length() ; k++)
	{
		out[j] = keypad[digit][k];
		generate_names(in,out,i+1,j+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string in;
	char output[1000];

	cin>>in;
	generate_names(in,output,0,0);

	return 0;
}