class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }

        int left=0;
        int right=s.size()-1;

        while(left<=right){

            if(isalnum(s[left])==false){
                left++;
                continue;
            }
            if(isalnum(s[right])==false){
                right--;
                continue;
            }

            char l=tolower(s[left]);
            char r=tolower(s[right]);

            if(l!=r){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};