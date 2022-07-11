// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class person{
public:
	string name;
	ll age;

	// Constructor
	person(string S,ll x){
		name = S;
		age = x;
	}
};

class person_compare{
public:
	bool operator()(person a,person b){
		return(a.age < b.age);
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,k;

    cin>>n; // n = 5
    priority_queue<person,vector<person>,person_compare> P;
    for(i=0 ; i<n ; i++){
    	string name;
    	ll age;
    	cin>>name>>age;
    	person p(name,age);
    	P.push(p);
    }

    cin>>k;		// k=2 (Top 2)
    for(i=1 ; i<=k ; i++){
    	person x = P.top();
    	cout<<x.name<<" "<<x.age<<"\n";
    	P.pop();
    }

   
    return 0;
}

