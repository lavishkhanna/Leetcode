int func(vector<int>& nums,int ind,vector<int>&v){

    if(ind>=nums.size()){
        return 0;
    }

    if(v[ind]!=-1){
        return v[ind];
    }
    

    int take=nums[ind]+func(nums,ind+2,v);
    int no=func(nums,ind+1,v);

    v[ind]=max(take,no);

    return max(take,no);
}

class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int>v (nums.size()+1,-1);


        return func(nums,0,v);
    }
};