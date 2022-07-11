#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll N,key,i;

	vector<ll> V;

	cin>>N;
	ll A[N];
	for(i=0 ; i<N ; i++)
		cin>>A[i];
	cin>>key;

	for(i=0 ; i<N ; i++)
	{
		if(A[i] == key)
			V.push_back(i);
	}

	for(i=0 ; i<V.size() ; i++)
		cout<<V[i]<<" ";
	cout<<"\n";

	return 0;
}

