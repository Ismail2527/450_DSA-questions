//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if (q1.empty())
        return -1; // or any appropriate value to indicate empty stack

    // Move all elements except the last one from q1 to q2
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }

    // The last element remaining in q1 is the top of the stack
    int poppedValue = q1.front();
    q1.pop();

    // Swap the names of q1 and q2 so that q1 always has the elements for the next push
    swap(q1, q2);

    return poppedValue; // Return the popped value
}
