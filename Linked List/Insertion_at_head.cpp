#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node{
public:
	ll data;
	node *next;

	// Constructor
	node(ll d){
		data = d;
		next = NULL;
	}
};

void insert_at_head(node *&head,ll d){

	if(head == NULL){
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n->next = head;
	head = n; 
}

void print(node *head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *head;

	head = NULL;
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	print(head);

	return 0;
}

