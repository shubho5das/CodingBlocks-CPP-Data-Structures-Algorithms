// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

ll find_max_area(ll a[],ll n)
{
    stack<ll> s;
    ll maxArea = 0;
   	
   	// Step 1
    for (int i = 0; i < n; i++)
    {
    	// Special Case	
        if (s.empty()){
            s.push(i);
            continue;
        }
      	
      	if(a[i] >= a[s.top()]){
      		s.push(i);
      	}
      	else if(a[i] < a[s.top()]){
      		// Popping all bar having height greater than a[i],
      		 // and, finding the area of that bar(considering that bar as the minimum height of rectangle)
        	while (!s.empty() && a[i] < a[s.top()])
            {
                ll x = s.top();
                s.pop();
                ll area = 0;
                if (s.empty())
                    area = a[x] * i;
                else
                    area = a[x] * (i - s.top() - 1);
                
                if(area > maxArea)
                	maxArea = area;
            }
            s.push(i);
        }
    }

    // Step 2
    // If stack does not become empty, 
    while (!s.empty())
    {
        ll area = 0;
        ll x = s.top();
        s.pop();
        if (s.empty())
            area = a[x] * n;
        else
            area = a[x] * (n - x);

        if(area > maxArea)
        	maxArea = area;
    }

    return maxArea;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,ans;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }

    ans = find_max_area(A,n);
    cout<<ans<<"\n";
   
    return 0;
}



