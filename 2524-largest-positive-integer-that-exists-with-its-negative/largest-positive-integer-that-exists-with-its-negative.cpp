int larg(vector<int>& v){
    
    unordered_map<int,int> omap;
    
    int max=0;
    
    for(int i=0;i<v.size();i++){
        
        if( (v[i]/abs(v[i])) == -1 ){
            
            pair p=make_pair(v[i],1);
            omap.insert(p);
            
        }
    }
    
    for(int i=0;i<v.size();i++){
        
        if( (v[i]/abs(v[i])) == 1 ){
            
            unordered_map<int,int>::iterator it=omap.find(-1*v[i]);
            
            if(it!=omap.end()){
                
                if(max < v[i]){
                    max=v[i];
                }
                
            }
            
        }
        
    }
    if(max==0){
        return -1;
    }
    return max;
    
}

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=larg(nums);
        return ans;
    }
};