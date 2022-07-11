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

ll length(node *head){

	ll count;

	count = 0;
	while(head != NULL ){
		count += 1;
		head = head->next;
	}
	return(count);
}

void insert_at_head(node *&head,ll d){
	if(head == NULL){
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n->next = head;
	head = n;
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

void insert_at_middle(node *&head,ll d,ll p){
	ll i;

	// Special Case- insertion at head
	if(head == NULL || p==0){
		insert_at_head(head,d);
	}
	// Special Case- insertion at tail
	if(p > length(head))
		insert_at_tail(head,d);

	node *temp = head;
	//Taking (p-1) jumps
	for(i=1 ; i<=(p-1) ; i++)
		temp = temp->next;
	node *n = new node(d);
	n->next = temp->next;
	temp->next = n;

	return;
}

void delete_at_head(node *&head){
	if(head == NULL)
		return;

	node *temp = head->next;
	delete head;
	head = temp;
	return;
}

void delete_at_tail(node *&head){
	if(head == NULL)
		return;

	node *tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	node *prev = head;
	while(prev->next->next != NULL)
		prev = prev->next;

	delete tail;
	prev->next = NULL; 
	return;
}

void delete_in_middle(node *&head,ll p){
	ll i;

	if(head == NULL)
		return;
	if(p >= length(head)){
		delete_at_tail(head);
		return;
	}

	node *temp = head;
	for(i=1 ; i<=p ; i++ )
		temp = temp->next;
	node *prev = head;
	while(prev->next->next != temp->next)
		prev = prev->next;
	prev->next = temp->next;
	delete temp;
	
	return;
}

void print(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

int main(){

	node *head = NULL;

	insert_at_head(head,1);
	insert_at_tail(head,2);
	insert_at_tail(head,3);
	insert_at_tail(head,4);
	insert_at_tail(head,5);
	print(head);
	delete_in_middle(head,2);
	print(head);
	delete_at_head(head);
	print(head);
	delete_at_tail(head);
	print(head);

	return 0;
}