class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }

        vector<int>vx=nums;

        sort(vx.begin(),vx.end());

        vector<int>vx_d=nums;

        sort(vx_d.begin(),vx_d.end(),greater<int>());

        if(nums!=vx){
            if(nums!=vx_d){
                return false;
            }
        }
        return true;
    }
};