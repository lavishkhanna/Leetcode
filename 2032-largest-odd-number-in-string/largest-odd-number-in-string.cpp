class Solution {
public:
    string largestOddNumber(string num) {
        int lst=num.size()-1;
        int ind=0;
        while(lst>=0){
            int x= num[lst]-'0';
            cout<<x<<endl;
            if(x%2!=0){
                ind=lst;
                break;
            }
            lst--;
        }
        
        

        if(lst<0){
            return "";
        }
        

        return num.substr(0,ind+1);

    }
};