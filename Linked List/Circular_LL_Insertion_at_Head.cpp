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

void insert_at_head_circular(node *&head, ll data){
	
	node *n = new node(data);
	node *temp = head;

	// Step 1
	n->next = head;
	//Step 2
	if(head == NULL)
		n->next = n;
	else{
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = n;
	}
	// Step 3
	head = n;

	return;
}

void print_circular(node*head){

	node *temp = head;

	if(head == NULL)
		return;

	while(temp->next != head){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<" ";

	return;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *head = NULL;

	insert_at_head_circular(head,4);
	insert_at_head_circular(head,3);
	insert_at_head_circular(head,2);
	insert_at_head_circular(head,1);
	print_circular(head);
	cout<<"\n";

	return 0;
}




