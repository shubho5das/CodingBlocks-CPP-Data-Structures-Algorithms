// Aim: Replace "pi" with 3.14

#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	char c;
	ll n,i;

	cin>>n;
	vector<char> S;
	vector<char> PI{'3','.','1','4'};

	for(i=0;i<n;i++)
	{
		cin>>c;
		S.push_back(c);
	}

	for(i=0 ; i <=(n-2) ; )
	{
		if( S[i]=='p'&& S[i+1]=='i' )
		{
			S.erase(S.begin()+i,S.begin()+i+2);
			S.insert(S.begin()+i,PI.begin(),PI.end());

			n = S.size();
			i += 4;
		}
		else
			i += 1;
	}

	for(i=0;i<n;i++)
		cout<<S[i];
	cout<<"\n";

	return 0;
}
