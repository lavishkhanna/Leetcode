class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }

        vector<int>vx;

        for(int i=0;i<v1.size();i++){
            vx.push_back(v1[i]);
        }
        for(int i=0;i<v2.size();i++){
            vx.push_back(v2[i]);
        }
        return vx;
    }
};