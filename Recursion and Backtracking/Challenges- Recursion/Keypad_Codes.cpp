#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

string keypad[] = {"0","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

void generate_codes(string &in,char out[],ll i,ll j,ll &count)
{
	string key;
	ll k;

	// Base Case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<" ";
		count += 1;
		return;
	}

	// Recursive Case

	key = keypad[(ll)(in[i] - '0')];
	for(k=0 ; k<key.length() ; k++)
	{
		out[j] = key[k];
		generate_codes(in,out,i+1,j+1,count);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll i,j,count;
	string in;
	char out[1005];

	cin>>in;

	count = 0;
	generate_codes(in,out,0,0,count);
	cout<<"\n";
	cout<<count<<"\n";

	return 0;
}


