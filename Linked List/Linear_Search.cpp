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

void print(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

ll linear_search(node *head,ll key){
	ll index;

	index = 0;
	while(head->next != NULL){

		if(head->data == key)
			return(index);
		index += 1;
		head = head->next;
	}
	return(-1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *head = NULL;
	insert_at_head(head,1);
	insert_at_tail(head,2);
	insert_at_tail(head,3);
	insert_at_tail(head,4);
	print(head);

	cout<<"1 located at index value = "<<linear_search(head,1)<<"\n";
	cout<<"3 located at index value = "<<linear_search(head,3)<<"\n";
	cout<<"0 located at index value = "<<linear_search(head,0)<<"\n";

	return 0;
}