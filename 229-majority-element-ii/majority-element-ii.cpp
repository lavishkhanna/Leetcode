#include<unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
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

        int ele=nums.size()/3;
        vector<int>v;
        while(it!=omap.end()){

            // cout<<it->first<<" "<<it->second<<endl;
            if(it->second>ele){
                maxi=it->second;
                v.push_back(it->first);
            }
            it++;
        }
        return v;
    }
};