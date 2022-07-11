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

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *head = NULL;
	node *mid;
	ll n;

	cin>>n;
	take_input(head,n);
	mid = find_mid(head);
	cout<<"Mid Value = "<<mid->data<<"\n";
	return 0;

}
