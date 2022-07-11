#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

template<typename T>
class my_queue{
private:
	T *A;
	ll F,R,current_size,max_size;
public:
	//Constructor
	my_queue(ll n=10){ 	// By default, n=10 
		A = new T[n];	 // ie, if we do not use parameterised constructor,
		current_size  = 0;// max_size would be set to 10, by default.
		max_size = n;
		F = 0;
		R = (max_size-1);
	}

	bool full(){
		return(current_size == max_size);  
	}

	bool empty(){
		return(current_size==0);
	}

	void push(T data){
		if(!full()){
			R = (R+1)%max_size;
			A[R] = data;
			current_size += 1;
		}
	}

	void pop(){
		if(!empty()){
			F = (F+1)%max_size;
			current_size -= 1;
		}
	}

	T front(){
		if(!empty())
			return(A[F]);
	}

	T back(){
		if(!empty())
			return(A[R]);
	}

	ll size(){
		return(current_size);
	}

	// Destructor
	~my_queue(){
		if(A != NULL){
			delete [] A;
			A = NULL;
		}
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    my_queue<ll> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout<<Q.front()<<"\n";
   	Q.pop();
   	Q.push(10);
   	
   	// Printing the Queue, by popping each of its elements
   	while(!Q.empty()){
   		cout<<Q.front()<<" ";
   		Q.pop();
   	}
   	cout<<"\n";

    return 0;
}

