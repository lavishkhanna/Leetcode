class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char,vector<int>> freq;
        
        int as=0;
        
        for(int i=0;i<s.size();++i){
            int j=i;
            while(j<s.size() && s[j]==s[i]){
                ++j;
            }
            freq[s[i]].push_back(j-i);
            i=j-1;
        }
        
        for(auto& x : freq){
            if(x.second.empty()){
                continue;
            }
            sort(x.second.begin(),x.second.end());
            int sz=x.second.size();
            as=max(as,x.second.back()-2);
            
            if(sz>1){
                as=max(as,min(x.second[sz-1]-1,x.second[sz-2]));
            }
            if(sz>2){
                as=max(as,x.second[sz-3]);
            }
            
        }
        
        if(as==0){
            as=-1;
        }
        return as;
    }
    
};