class Solution {
public:
    void solve(vector<int> c, int t,vector<vector<int>>& ans,vector<int> output,int index){
        if(t <= 0){
            if(t == 0){
                ans.push_back(output);
            }
            return;
        }

        for(int i = index; i < c.size(); i++){
            if(c[i] > t) break;
            output.push_back(c[i]);
            solve(c,t-c[i],ans,output,i);
            output.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> output;
        solve(candidates,target,ans,output,0);
        return ans;
    }
}; 