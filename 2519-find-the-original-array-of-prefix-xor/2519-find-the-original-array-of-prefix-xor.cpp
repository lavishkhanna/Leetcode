class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int n=pref.size();
        ans.push_back(pref[0]);
        for(int i=1;i<n;i++)
        {
           ans.push_back(pref[i-1]^pref[i]);
        }
        return ans;
        
    }
};