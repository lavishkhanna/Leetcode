class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>omap;

        int f=0;
        int l=0;
        int ans=0;

        for(int i=0;i<s.size();i++){
            
            while (omap.count(s[i])>0){
                omap.erase(s[f]);
                f++;
            }
            omap[s[i]]=1;
            ans=max(ans,i-f+1);

        }
        return ans;
    }
};