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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>>v;
            return v;
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>>res;



        while(!q.empty()){

            int sz=q.size();


            int cnt=0;
            vector<int>ans;

            while(cnt<sz){

                TreeNode * cur=q.front();
                q.pop();


                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }

                ans.push_back(cur->val);
                cnt++;
            }
            res.push_back(ans);
        }
        return res;
    }
};