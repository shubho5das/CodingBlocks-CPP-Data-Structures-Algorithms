#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

string table[] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generate_codes(string &in,char out[],ll i,ll j)
{
	ll k,index;
	string key;

	// Base Case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<"\n";
		return;
	}

	// Recursive Case

	index = (ll)(in[i] - '0');
	key = table[index];

	for(k=0 ; k<key.length() ; k++)
	{	
		out[j] = key[k];
		generate_codes(in,out,i+1,j+1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	char out[50];
	string in;

	cin>>in;
	generate_codes(in,out,0,0);

	return 0;
}

