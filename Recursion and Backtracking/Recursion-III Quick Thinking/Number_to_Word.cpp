#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	ll i,N,rem,count;

	string num[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	vector<ll> digit;

	cin>>N;

	count = 0;
	while(N>0)
	{
		rem = N%10;
		digit.push_back(rem);

		count += 1;
		N = N/10;
	}
	reverse(digit.begin(),digit.end());

	for(i=0 ; i<count ; i++)
	{
		cout<<num[digit[i]]<<" ";
	}
	cout<<"\n";

	return 0;
}