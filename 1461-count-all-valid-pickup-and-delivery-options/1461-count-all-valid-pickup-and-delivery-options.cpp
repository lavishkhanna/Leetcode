class Solution {
public:
    const int MOD = 1e9 + 7;  
    vector<long long> dp;    

    int countOrders(int numberOfPairs) {
        dp.resize(numberOfPairs + 1); 

        
        dp[0] = 1;

        
        for (int currentPairs = 1; currentPairs <= numberOfPairs; currentPairs++) {
            
            dp[currentPairs] = dp[currentPairs - 1] * (2 * currentPairs - 1) * currentPairs % MOD;
        }

        return dp[numberOfPairs]; 
    }
};