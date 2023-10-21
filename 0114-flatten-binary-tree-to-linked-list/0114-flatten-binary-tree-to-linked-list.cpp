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
TreeNode *func(TreeNode * root){

    if(root==NULL){
        return NULL;
    }

    TreeNode * lft=func(root->left);

    TreeNode * rgh=func(root->right);
    if(lft==NULL){
        return root;
    }

    TreeNode * temp=lft;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    root->right=lft;
    temp->right=rgh;

    root->left=NULL;

    return root;
}

class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode * res=func(root);
        root=res;
    }
};