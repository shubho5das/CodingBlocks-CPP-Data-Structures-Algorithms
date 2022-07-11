#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void count_subsets(string &in,char out[],ll i,ll j,ll &count,vector<string> &V)
{
	// Base Case
	if(in[i]=='\0')
	{
		out[j] = '\0';
		V.push_back(out);
		//cout<<out<<" ";
		count += 1;
		return;
	}

	// Recursive Case

	// Case 1: Include in[i]
	out[j] = in[i];
	count_subsets(in,out,i+1,j+1,count,V);
	// Case 2: Exclude in[i]
	count_subsets(in,out,i+1,j,count,V);

}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	string in;
	ll result,count,i;
	char out[10];

	cin>>in;
	count = 0;

	vector<string> V;

	count_subsets(in,out,0,0,count,V);
	reverse(V.begin(),V.end());
	for(i=0 ; i<V.size();i++)
		cout<<V[i]<<" ";
	cout<<"\n";
	cout<<count<<"\n";

	return 0;
}