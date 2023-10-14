class Solution {
public:
    bool solve(TreeNode* root, TreeNode* sub){
        if(!root & !sub) return true;
        if(!root || !sub) return false;
        
        if(root->val != sub->val) return false;
        bool left = solve(root->left,sub->left);
        bool right = solve(root->right,sub->right);

        if(left && right) return true;
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root) return false;

        if(solve(root,subroot)) return true;
        else{
            return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
        }
    }
};