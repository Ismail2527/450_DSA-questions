//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    void InsertAtTail(Node* &head,Node* &tail,int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *newhead = NULL,*newtail = NULL,*curr1 = head1,*curr2 = head2;
        while(curr1 != NULL and curr2 != NULL){
            if(curr1->data == curr2->data){
                InsertAtTail(newhead,newtail,curr1->data);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }else if(curr1->data<curr2->data){
                curr1 = curr1->next;
            }else{
                curr2 = curr2->next;
            }
        }
        return newhead;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends