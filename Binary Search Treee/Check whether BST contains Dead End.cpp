//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void full(Node *root,map<int,bool>&leafmap,map<int,bool>&realmap){
        
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr){
            leafmap[root->data] = true;
        }else{
            realmap[root->data] = true;   
        }
        full(root->left,leafmap,realmap);
        full(root->right,leafmap,realmap);
    }
    bool solve(map<int,bool>leafmap,map<int,bool>realmap){
        if(leafmap.size() == 1){
            return false;
        }
        for (auto it : leafmap) {
            int val = it.first;
            if ((realmap.find(val - 1) != realmap.end() && realmap.find(val + 1) != realmap.end()) || (val - 1 == 0)) {
                return true;
            }
        }
        return false;

        
    }
    bool solve2(Node* root,int max,int min){
        if(!root) return false;
        if(max == min) return true;
        return solve2(root->left,root->data-1,min) or solve2(root->right,min,root->data+1);
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        //map<int,bool>leafmap;
        //map<int,bool>realmap;
        //full(root,leafmap,realmap);
        //return solve(leafmap,realmap);
        return solve2(root,INT_MAX,1);   
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends