void swap(vector<char>& s,int i,int j){

    char a=s[i];
    char b=s[j];

    a=a^b;

    b= a^b;

    a=a^b;

    s[j]=b;
    s[i]=a;

    return;
}

class Solution {
public:
    void reverseString(vector<char>& s) {
        

        int left=0;
        int r=s.size()-1;

        while(left<r){
            swap(s,left,r);
            left++;
            r--;
        }
        return;
    }
};