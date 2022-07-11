/* Coding Blocks Editorial:
For every bar ‘x’, 
 we calculate the area with ‘x’ as the smallest bar in the rectangle. 
If we calculate such area for every bar ‘x’ and find the maximum of all areas, 
 our task is done. 
How to calculate area with ‘x’ as smallest bar? 
We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. 
Let us call these indexes as ‘left index’ and ‘right index’ respectively. 
We traverse all bars from left to right, maintain a stack of bars. 
Every bar is pushed to stack once. 
A bar is popped from stack when a bar of smaller height is seen. 
When a bar is popped, we calculate the area with the popped bar as smallest bar. 
How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. */

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
            area = a[x] * (n - s.top() -1);

        if(area > maxArea)
        	maxArea = area;
    }

    return maxArea;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans,n;
    ll A[] = {4,2,0,3,2,5};

    n = sizeof(A)/sizeof(A[0]);
    ans = find_max_area(A,n);
    cout<<ans<<"\n";

    return 0;
}