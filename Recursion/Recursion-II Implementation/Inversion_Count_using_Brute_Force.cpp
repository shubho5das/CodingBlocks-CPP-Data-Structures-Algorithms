#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		

	ll i,j,n,count;

	ll A[] = {1,5,2,6,3,0};
	n = sizeof(A)/sizeof(A[0]);

	count = 0;
	for(i=0 ; i<=(n-2) ; i++)
	{
		for(j=(i+1) ; j<=(n-1) ; j++)
		{
			if(A[j] < A[i])
				count += 1;
		}
	}

	cout<<count<<"\n";




	return 0;
}




