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

node* recursive_reverse(node*head){
	
	//Base Case
	if(head->next == NULL || head==NULL)
		return head;

	// Recursive Case
	node *small_head = recursive_reverse(head->next);

	node *temp = head->next;
	temp->next = head;
	head->next = NULL;
	return(small_head);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	node *head = NULL;

	cin>>n;
	take_input(head,n);
	print(head);
	head = recursive_reverse(head);
	print(head);
	
	return 0;	
}


