vector<vector<int>> func(int n){
    if(n==2){
        vector<int>vs;
        vector<vector<int>>v;
        vs.push_back(1);
        v.push_back(vs);
        vector<int>vss;
        vss.push_back(1);
        vss.push_back(1);
        v.push_back(vss);
        return v;
    }
    if(n==1){
        vector<int>vs;
        vector<vector<int>>v;
        vs.push_back(1);
        v.push_back(vs);
        return v;
    }

    vector<vector<int>>ch=func(n-1);

    vector<int>req=ch[ch.size()-1];

    vector<int>fill;
    fill.push_back(1);

    for(int i=0;i<req.size()-1;i++){
        fill.push_back(req[i]+req[i+1]);
    }
    fill.push_back(1);

    ch.push_back(fill);

    return ch;

}


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v=func(numRows);
        return v;
    }
};