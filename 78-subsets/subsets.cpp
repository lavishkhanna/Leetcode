void func(int ind,vector<int> arr, vector<int>& ds, vector<vector<int>>& ans){


    if(ind>=arr.size()){
        ans.push_back(ds);
        return;
    }



    ds.push_back(arr[ind]);
    func(ind+1,arr,ds,ans);
    ds.pop_back();

    func(ind+1,arr,ds,ans);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>ds;
        func(0,nums,ds,ans);
        return ans;
    }
};