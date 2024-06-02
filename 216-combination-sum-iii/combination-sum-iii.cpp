// class Solution {
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
        
//     }
// };




// func(ind,ds,ans,mp,sum,n,k){

//     if(ind>=k){
        
//         if(sum==n){
//             ans.push_back(ds);
//         }
//         return;
//     }
//     if(sum>n){
//         return;
//     }





//     for(auto i:mp){
//         i->second=false;
//         ds.push_back(i->first);
//         func(ind+1,ds,ans,mp,sum+i->first,n,k);

//         ds.pop_back();
//         i->second=true;
//     }
// }


class Solution {
private:
    void solve(vector<vector<int>> & ans, vector<int> & op, int st, int k, int n, int & sum , int arr[]){
        if(k == 0){
            if(sum == n){
                sort(op.begin(), op.end());
                ans.push_back(op);
            }
            return;
        }
        for(int i = st; i < 9; ++i){
            sum += arr[i];
            op.push_back(arr[i]);
            solve(ans, op, i+1, k-1, n, sum, arr);
            sum -= arr[i];
             op.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int arr[9] = {1,2,3,4,5,6,7,8,9};
        vector<int> op;
        int st = 0;
        int sum = 0;
        solve(ans, op, st, k, n, sum, arr);
        return ans;
    }
};