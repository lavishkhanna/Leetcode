class Solution {
public:
long long flowerGame(int n, int m) {
    long long ans = 0;
    for(int i = 1; i <= min(n, m); i++){
        ans += (long long)((m - i + 1)/2);
        ans += (long long)((n - i + 1)/2);
    }
    return ans;
}
};