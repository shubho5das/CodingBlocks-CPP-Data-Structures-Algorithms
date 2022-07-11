#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void check_subset_sum(ll in[],ll out[],ll i,ll j,ll n,ll &flag)
{
	ll k,sum;

	// Base Case
	if(i == n)
	{	
		sum = 0;
		for(k=0 ; k<j ; k++)
		{
			//cout<<out[k]<<" ";
			sum += out[k];
		}
		//cout<<"\n";

		if(sum == 0 && j>0)
			flag = 1;
		
		return;
	}

	// Recursive Case

	// Case 1: Include in[i]
	out[j] = in[i];
	check_subset_sum(in,out,i+1,j+1,n,flag);
	// Case 2: Exclude in[i]
	check_subset_sum(in,out,i+1,j,n,flag);

}

int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll T,n,i,flag;
	
	cin>>T;
	while(T--)
	{
		cin>>n;

		ll in[10],out[10];
		for(i=0 ; i<n ; i++)
			cin>>in[i];

		flag = 0;
		check_subset_sum(in,out,0,0,n,flag);

		if(flag==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}

	return 0;
}
