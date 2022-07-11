// KEEP CALM and Enjoy the Problem B-)

// Implementation Problem, based on Queues- must do it, some time later!

/* Problem:
There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.

Now, we are given two things:

1)The calling order in which all the processes are called.
2)The ideal order in which all the processes should have been executed.

Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

We have to find out the unit of time required to complete all the process such that a process is executed from the ideal order only when it exists at the same index in the calling order. We can push the first term from the calling order to the last thus rotating the order.
*/

/* Editorial:
The Idea is to Store the Calling order in Queue and the ideal order in an Array.
Then compare front element of the queue with the ideal order.
If it matches then increment the time and remove the element.
Else, Dequeue the element and enqueue it again.
The loop will run till the queue is consumed totally.
*/

// Editorialist's Code:
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int importanceOfTime(queue<int> &q, const vector<int> &arr)
{
    //arr is the ideal order
    //q is the calling order
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (q.front() == arr[i])
        {
            ans++;
            q.pop();
        }
        else
        {
            while (q.front() != arr[i])
            {
                int var = q.front();
                q.push(var);
                q.pop();
                ans++;
            }
            ans++;
            q.pop();
        }
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << importanceOfTime(q, v);

    return 0;
      
}



