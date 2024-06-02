void func(int ind,int open,int close, string& ds, vector<string>& ans,int n){


    if(ind>= (2*n)){
        ans.push_back(ds);
        return;
    }

    if (open<n){

        ds.push_back('(');
        func(ind+1,open+1,close,ds,ans,n);
        ds.pop_back();
    }

    if(close<open){
        ds.push_back(')');
        func(ind+1,open,close+1,ds,ans,n);
        ds.pop_back();
    }
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {

        string ds;
        vector<string>ans;

        func(0,0,0,ds,ans,n);

        return ans;
    }
};