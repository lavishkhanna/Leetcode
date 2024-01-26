class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>omap;

        for(int i=0;i<nums.size();i++){
            if(omap.count(nums[i])>0){
                continue;
            }
            else{
                pair<int,int>p=make_pair(nums[i],i);
                omap.insert(p);
            }
        }
        vector<int>v;

        for(int i=0;i<nums.size();i++){

            int ch=(target-nums[i]);

            if(omap.count(ch)>0){

                if(i==omap[ch]){
                    continue;
                }
                
                v.push_back(i);
                v.push_back(omap[ch]);
                break;
            }

        }
        return v;
    }
};