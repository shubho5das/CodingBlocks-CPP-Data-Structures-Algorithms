#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll i,n;

	string S;
	cin>>S;

	vector<char> V(S.begin(),S.end());
	n = V.size();

	for(i=0 ; i<=(n-2) ; )
	{
		if(V[i] == V[i+1])
		{
			while(V[i] == V[i+1] && i<=(n-2))
			{
				V.erase(V.begin() + (i+1));
				n = V.size();
			}
		}
		else
			i += 1;
	}
	n = V.size();

	for(i=0 ; i<n ; i++)
		cout<<V[i];
	cout<<"\n";

	return 0;
	
}


