class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            pair<int, int> ps = make_pair(count, i);
            v.push_back(ps);
        }
        for (int i = 0; i < v.size(); i++) {
            pq.push(v[i]);
        }
        vector<int> vx;
        for (int i = 0; i < k; i++) {
            pair<int, int> p = pq.top();
            
            int x = p.second;

            vx.push_back(x);
            pq.pop();
        }
        return vx;
    }
};
