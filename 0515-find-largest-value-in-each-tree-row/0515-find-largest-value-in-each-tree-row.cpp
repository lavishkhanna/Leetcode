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

vector<int> func(TreeNode * root){
    queue<TreeNode*> q;
    q.push(root);
  

    vector<int>x;


    while(q.empty()==false){
        int sz=q.size();

        int cnt=0;
        
        priority_queue<int> pqs;
        while(cnt<sz){

            TreeNode * curr=q.front();
            q.pop();
            
            pqs.push(curr->val);

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            cnt++;
        }
        x.push_back(pqs.top());
        

    }
    return x;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            vector<int>v;
            return v;
        }
        return func(root);
    }
};