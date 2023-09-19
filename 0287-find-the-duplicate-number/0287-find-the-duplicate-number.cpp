class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>omap;
        for(int i=1;i<nums.size();i++){
            omap[i]=0;
            cout<<i<<endl;
        }
        for(int i=0;i<nums.size();i++){
            if(omap.count(nums[i])>0){
                omap.erase(nums[i]);
            }
            else{
                return nums[i];
            }
        }
        return 0;
        
    }
};