vector<string> func(string digits){
        if(digits.size()==0){
            vector<string> v;
            string s="";
            v.push_back(s);
            return v;
        }

        vector<string> v=func(digits.substr(1));

        vector<string> dict = {"", "", "abc", "def", "ghi","jkl", "mno","pqrs", "tuv", "wxyz"};

        // char ind=digits[0];
        // ind=float(ind);
        // ind=int(ind);
        string req = dict[digits[0] - '0'];

        // string req=dict[ind];
        vector<string> vec;

        for(int i=0;i<req.size();i++){
            for(int j=0;j<v.size();j++){
                vec.push_back(req[i]+v[j]);
            }
        }
        return vec;

}

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits==""){
            vector<string>vs;
            return vs;
        }
        vector<string>res=func(digits);
        return res;





    }
};