class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 1, -1); // Initialize vector with size n+1 and fill it with -1

        return helper(n, v);
    }

    int helper(int n, vector<int>& v) {
        if (n <= 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        if (v[n] != -1) {
            return v[n];
        }

        int f = helper(n - 1, v);
        int s = helper(n - 2, v);

        v[n] = f + s;

        return v[n];
    }
};
