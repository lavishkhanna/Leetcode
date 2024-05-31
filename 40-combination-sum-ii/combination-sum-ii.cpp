void func(int ind,vector<int>& arr,int target,vector<int>& ds,vector<vector<int>>& ans){


    if(target==0){
        ans.push_back(ds);
        return;
    }

    // if(ind>=arr.size()){
    //     return;
    // }

    for(int i=ind;i<arr.size();i++){
        if(i!=ind && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        ds.push_back(arr[i]);
        func(i+1,arr,target-arr[i],ds,ans);
        ds.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int ind=0;
        int sum=0;
        vector<int>ds;
        vector<vector<int>>ans;

        func(ind,arr,target,ds,ans);
        return ans;
    }
};



// class Solution {
// public:
//     void getcombinations(int i, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& output)
//     {
//         if(target==0)
//         {
//             output.push_back(temp);
//             return;
//         }
//         for(int j=i; j<candidates.size(); j++)
//         {
//             if(j>i && candidates[j]==candidates[j-1])
//             continue;
//             if(candidates[j]>target) break;
//             temp.push_back(candidates[j]);
//             getcombinations(j+1, target-candidates[j], candidates, temp, output);
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> output;
//         vector<int> temp;
//         getcombinations(0, target, candidates, temp, output);
//         return output;
//     }
// };