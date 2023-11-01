class Solution {
public:
    long long minSum(vector<int>& A, vector<int>& B) {
        long long sa = 0, sb = 0, a0 = 0, b0 = 0;
        for (int a: A) {
            a0 += a == 0;
            sa += max(a, 1);
        }
        for (int b: B) {
            b0 += b == 0;
            sb += max(b, 1);
        }
        if (sa < sb && a0 == 0) return -1;
        if (sa > sb && b0 == 0) return -1;
        return max(sa, sb);
    }
};
