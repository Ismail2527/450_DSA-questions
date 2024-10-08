//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    int valid_pair(string str,int s,int e){
        stack<char>st;
        if(s>e){
            return -1;
        }
        for(int i=s; i<=e; i++){
            if(str[i] == '('){
                st.push(str[i]);
            }else if(str[i] == ')'){
                st.pop();
                if(st.empty()){
                    return i;
                }
            }
        }
        return -1;
    }
    Node* solve(int s, int e, string str){
        if(s>e){
            return nullptr;
        }
        
        int num =0;
        while(s<str.size() && isdigit(str[s])){
            num = num*10 + str[s] - '0';
            s++;
        }
        Node *root = new Node(num);
        int index =-1;
        if(s<str.size() && str[s] == '('){
            index = valid_pair(str,s,e);
        }
        if(index != -1){
            root->left = solve(s+1,index-1,str);
            root->right = solve(index+2,e-1,str);
        }
        return root;
    }
    Node *treeFromString(string str){
        // code here
        return solve(0,str.size()-1,str);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends