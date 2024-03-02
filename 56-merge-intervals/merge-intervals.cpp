class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& s) {
        vector<vector<int>>v;

        sort(s.begin(),s.end());
        v.push_back(s[0]);

        int cur=0;
        for(int i=1;i<s.size();i++){

            if(s[i][0]<= v[cur][1]){

                if(s[i][1]>=v[cur][1]){
                    v[cur][1]=s[i][1];
                }
                continue;

                
            }
            else{
                v.push_back(s[i]);
                cur++;
            }
        }
        return v;
    }
};