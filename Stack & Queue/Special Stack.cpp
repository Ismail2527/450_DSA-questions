//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

stack<int> minStack;  // Auxiliary stack to store minimums

// Function to push an element onto the stack
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
    
    // Push the minimum element onto the minStack
    if (minStack.empty() || a <= minStack.top()) {
        minStack.push(a);
    }
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	if (s.empty()) return -1;

    int topElement = s.top();
    s.pop();

    // Pop from minStack if the popped element is the current minimum
    if (topElement == minStack.top()) {
        minStack.pop();
    }

    return topElement;
}

int getMin(stack<int>& s){
	// Your code goes here
	if (minStack.empty()) return -1;

    return minStack.top();
}