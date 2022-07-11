#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string S;
	ll n,i;

	cin>>S;

	vector<char> V(S.begin(),S.end());
	n = V.size();

	for(i=0 ; i<=(n-2) ; i++)
	{
		if(V[i]==V[i+1])
		{
			V.insert(V.begin()+i+1,'*');

			n = V.size();
			i += 2;
		}
		else
			i += 1;

	}
	
	for(i=0 ; i<n ; i++)
		cout<<V[i];
	cout<<"\n";

	return 0;
}