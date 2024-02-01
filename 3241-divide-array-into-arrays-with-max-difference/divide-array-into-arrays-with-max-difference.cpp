class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>vs;
        
        for(int i=0;i<nums.size();i=i+3){
            int f=nums[i];
            int s=nums[i+1];
            int t=nums[i+2];
            
            if( abs(f-s)>k || abs(s-t)>k || abs(f-t)>k ){
                // vector<int>v;
                vector<vector<int>>v;
                return v;
            }
            vector<int>v;
            v.push_back(f);
            v.push_back(s);
            v.push_back(t);
            
            vs.push_back(v);
        }
        return vs;
    }
};