/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insert(TreeNode* head, int val){
        TreeNode* node=head;
        if(node==nullptr) return new TreeNode(val);
        if(val>node->val){
            node->right = insert(node->right,val);
        }else{
            node->left = insert(node->left,val);
        }
        return head;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* node=nullptr;
        int n=preorder.size();
        if(n==0)return node;
        for(int i=0;i<n;i++){
            node=insert(node,preorder[i]);
        }
        return node;

    }
};