// void func(int ind,vector<int>& arr,int sum,int target,vector<int> ds,vector<vector<int>>& ans){


//     if(sum==target){
//         ans.push_back(ds);
//         return;
//     }

//     if(ind>=arr.size()){
//         return;
//     }

//     for(int i=ind;i<arr.size();i++){
//         if(i!=ind && arr[i]==arr[i-1]){
//             continue;
//         }
//         ds.push_back(arr[i]);
//         func(i+1,arr,sum+arr[i],target,ds,ans);
//         ds.pop_back();
//     }
// }


// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
//         sort(arr.begin(),arr.end());
//         int ind=0;
//         int sum=0;
//         vector<int>ds;
//         vector<vector<int>>ans;

//         func(ind,arr,sum,target,ds,ans);
//         return ans;
//     }
// };
class Solution {
public:
    void comb(int i, vector<int> sub, vector<vector<int>> &ans, vector<int> candidates, int t){
        if(t == 0){
            ans.push_back(sub);
            return;
        }
        if(i == candidates.size()) return;
        if(t < candidates[i]) return;
        for(int ind=i;ind<candidates.size();ind++){
            if(ind>i && candidates[ind-1]==candidates[ind]) continue;
            sub.push_back(candidates[ind]);
            comb(ind+1, sub, ans, candidates, t-candidates[ind]);
            sub.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        comb(0, sub, ans, candidates, target);
        return ans;
    }
};