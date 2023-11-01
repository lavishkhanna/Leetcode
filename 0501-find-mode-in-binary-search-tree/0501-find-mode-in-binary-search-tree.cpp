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

 map<int,int>omap;

void func(TreeNode * root){
    if(root==NULL){
        // vector<pair<int,int>> v;
        return;
    }

    omap[root->val]++;

    func(root->left);
    func(root->right);

    return;


}

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // vector<pair<int,int>> v=func(root);
        func(root);

        // map<int,int> omap2;

        map<int,int>::iterator it=omap.begin();
        int max=INT_MIN;

        while(it!=omap.end()){
            cout<<it->first<<" "<<it->second<<endl;

            if(it->second > max){
                max=it->second;
            }
            it++;
        }

        map<int,int>::iterator its=omap.begin();


        vector<int>v;
        while(its!=omap.end()){
            if(its->second==max){
                v.push_back(its->first);
            }
            its++;
        }
        omap.clear();
        return v;


    }
};