// #pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numSquares(int n) {
        int sqrt_n=sqrt(n);
        if (sqrt_n*sqrt_n==n) return 1;//square

        vector<int> dp(n+1, 4);//Lagrange's 4-square
        for (int i=1; i<=sqrt_n; i++) 
            dp[i*i]=1;//squares
        for (int i=1; i<=n; i++){
            if (dp[i]==1) continue; //1 for square
            int sqrt_i=sqrt(i);
            int x=4;
            for(int j=1; j<=sqrt_i; j++){
                x=min(x, 1+dp[i-j*j]);
                if (x==2) break;// can not be smaller
            }
            dp[i]=x;
        }
        return dp[n];  
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();