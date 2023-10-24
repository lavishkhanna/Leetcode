class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int maxi=INT_MIN;
        int pref=1;
        int suf=1;

        for(int i=0;i<arr.size();i++){

            if(pref==0){
                pref=1;
            }
            if(suf==0){
                suf=1;
            }

            pref=pref*arr[i];
            suf=suf*arr[arr.size()-i-1];

            if(maxi< max(pref,suf)){
                maxi=max(pref,suf);
            }
        }
        return maxi;
    }
};