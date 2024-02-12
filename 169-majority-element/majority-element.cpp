#include<unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> omap;

        for(int i=0;i<nums.size();i++){

            if(omap.count(nums[i])>0){
                omap[nums[i]]=omap[nums[i]]+1;
            }
            else{
                pair<int,int> p;
                p.first=nums[i];
                p.second=1;
                omap.insert(p);
            }
        }

        unordered_map<int,int>::iterator it=omap.begin();


        int maxi=it->second;
        int max_e=it->first;
        while(it!=omap.end()){

            // cout<<it->first<<" "<<it->second<<endl;
            if(it->second>maxi){
                maxi=it->second;
                max_e=it->first;
            }
            it++;
        }
        return max_e;
    }
};