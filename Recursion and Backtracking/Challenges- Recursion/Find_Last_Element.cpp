#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

ll find_last_element(ll A[],ll N,ll key)
{
	ll i,flag,index;

	flag = 0;
	for(i=0 ; i<N ; i++)
	{
		if(A[i] == key)
			flag = 1;
	}
	// Speical Case
	if(flag == 0)
		return -1;

	for(i=0 ; i<N ; i++)
	{
		if(A[i] == key)
			index = i;
	}
	return(index);
}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll N,key,i;
	ll index;

	cin>>N;
	ll A[N];
	for(i=0 ; i<N ; i++)
		cin>>A[i];
	cin>>key;
	index = find_last_element(A,N,key);
	cout<<index<<"\n";

	return 0;
}

