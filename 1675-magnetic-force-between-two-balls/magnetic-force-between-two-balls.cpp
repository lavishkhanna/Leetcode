class Solution {
public:
    bool canBePlaced(int d, vector<int> &p, int m){
        int n = p.size();
        int c = 1, i = 0, j = 1; 
        while(j < n){
            if(p[j] - p[i] < d) ++j;
            else{
                i = j;
                ++j;
                ++c;
            }
        }
        return c >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int n = position.size();
        int lo = 1;
        int hi = position[n - 1] - position[0];
        while(hi - lo > 1){
            int mid = lo + (hi - lo)/2;
            if(canBePlaced(mid, position, m)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        if(canBePlaced(hi, position, m)) return hi;
        return lo;
    }
};