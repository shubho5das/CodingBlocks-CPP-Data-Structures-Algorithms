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

node* find_mid(node *head){

	if(head==NULL || head->next==NULL)
		return head;

	node *slow = head;
	node *fast = head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return(slow);
}

node *merge_sort(node *head){
	// Base Case
	if(head == NULL || head->next == NULL)
		return head;

	// Recursive Case
	//Step 1: Divide
	node *mid = find_mid(head);
	node *a = head;
	node *b = mid->next;
	mid->next = NULL;
	//Step 2: Recursively sort the 2 parts
	a = merge_sort(a);
	b = merge_sort(b);
	//Step 3: Merge back the 2 parts
	node *c = merge(a,b);
	return c;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *head = NULL;
	ll n;

	cin>>n;
	take_input(head,n);
	head = merge_sort(head);
	print(head);

	return 0;
}

