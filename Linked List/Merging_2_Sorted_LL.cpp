#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node
{
public:
	ll data;
	node* next;

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
	return;
}

void insert_at_tail(node *&head,ll d){

	if(head == NULL){
		head = new node(d);
		return;
	}

	node *tail = head;
	while(tail->next !=  NULL)
		tail = tail->next;
	tail->next = new node(d);
	return;
}
void print(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	} 
	cout<<"\n";
}

void take_input(node *&head,ll n){
	ll num,i;

	if(n==0)
		return;

	cin>>num;
	insert_at_head(head,num);
	for(i=1 ; i<=(n-1) ; i++){
		cin>>num;
		insert_at_tail(head,num);
	}
}

node* merge(node *a, node *b){

	// Base Case
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	// Recursive Case
	node *c;
	if(a->data <= b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n_a,n_b;
	node *a=NULL,*b=NULL,*c;

	cin>>n_a;
	take_input(a,n_a); // 1 3 4 7
	cin>>n_b;
	take_input(b,n_b); // 0 2 8 10
	c = merge(a,b);
	print(c);
	print(a);
	print(b);

	return 0;
}
