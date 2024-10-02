//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution
{
	public:
	    void Travers(Node* root,vector<string>&ans,string temp){
	        // base case
	        // base case
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
            return;
        }
        if (root->left) {
            Travers(root->left, ans, temp + '0');
        }
        if (root->right) {
            Travers(root->right, ans, temp + '1');
        }
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    // Code here
            priority_queue<Node*, vector<Node*>, cmp> q;
            for (int i = 0; i < N; i++) {
                Node* temp = new Node(f[i]);
                q.push(temp);
            }
            while (q.size() > 1) {
                Node* left = q.top();
                q.pop();
                Node* right = q.top();
                q.pop();
                Node* newnode = new Node(left->data + right->data);
                newnode->left = left;
                newnode->right = right;
                q.push(newnode);
            }
            Node* root = q.top();
            vector<string> ans;
            string temp;
            Travers(root, ans, temp);
            return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends