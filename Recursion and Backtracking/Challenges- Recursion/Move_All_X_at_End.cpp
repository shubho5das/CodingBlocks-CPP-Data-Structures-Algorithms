#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	string S;
	ll N,i,count_x;
	
	cin>>S;

	vector<char> V(S.begin(),S.end());
	N = V.size();

	count_x = 0;
	for(i=0 ; i<N ; )
	{
		if(V[i]=='x')
		{
			count_x += 1;
			V.erase(V.begin() + i);
			N = V.size();
		}
		else
			i += 1;
	}

	for(i=0 ; i<N ; i++)
		cout<<V[i];
	for(i=1 ; i<=count_x ; i++)
		cout<<"x";
	cout<<"\n";

	return 0;
}


