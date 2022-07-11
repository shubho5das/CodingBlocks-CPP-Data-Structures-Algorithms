#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void generate_subsequnce(string &in,char out[],ll i,ll j)
{
	// Base Case
	if(in[i]=='\0')
	{
		out[j] = '\0';
		cout<<out<<"\n";
		return;
	}

	// Recursive Case

	// Case 1: Include in[i]
	out[j] = in[i];
	generate_subsequnce(in,out,i+1,j+1);
	// Case 2: Do not include in[i]
	generate_subsequnce(in,out,i+1,j);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string input = "abc";

	char output[1000];
	generate_subsequnce(input,output,0,0);

	return 0;
}