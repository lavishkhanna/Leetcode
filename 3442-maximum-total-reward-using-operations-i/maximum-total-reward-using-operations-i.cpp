class Solution {
public:

    int maxTotalRewardRec(vector<int>& arr, int i, int lastSum)
    {
        if(i >= arr.size()) return 0;

        // Include
        int include = 0;
        if(arr[i] > lastSum)
        {
            include = arr[i] + maxTotalRewardRec(arr,i+1,lastSum + arr[i]);
        }
        // Exclude
        int exclude = 0 + maxTotalRewardRec(arr,i+1,lastSum);

        return max(include,exclude);
    }

    int maxTotalRewardMem(vector<int>& arr, int i, int lastSum, vector<vector<int>> &dp)
    {
        if(i >= arr.size()) return 0;
        if(dp[i][lastSum] != -1) return dp[i][lastSum];

        // Include
        int include = 0;
        if(arr[i] > lastSum)
        {
            include = arr[i] + maxTotalRewardMem(arr,i+1,lastSum + arr[i],dp);
        }
        // Exclude
        int exclude = 0 + maxTotalRewardMem(arr,i+1,lastSum,dp);

        return dp[i][lastSum] = max(include,exclude);
    }

    int maxTotalRewardTab(vector<int>& arr)
    {
        vector<vector<int>> dp(2001,vector<int>(4001,0));

        for(int i = arr.size()-1; i >= 0; i--)
        {
            for(int lastSum = 4000; lastSum >= 0; lastSum--)
            {
                int include = 0;
                if(arr[i] > lastSum)
                {
                    include = arr[i] + dp[i+1][lastSum+arr[i]];
                }
                // Exclude
                int exclude = 0 + dp[i+1][lastSum];

                dp[i][lastSum] = max(include,exclude);
            }
        }
        return dp[0][0];
    }

    int maxTotalRewardSO(vector<int>& arr)
    {
        vector<int> curr(4001,0);
        vector<int> next(4001,0);

        for(int i = arr.size()-1; i >= 0; i--)
        {
            for(int lastSum = 4000; lastSum >= 0; lastSum--)
            {
                int include = 0;
                if(arr[i] > lastSum)
                {
                    include = arr[i] + next[lastSum+arr[i]];
                }
                // Exclude
                int exclude = 0 + next[lastSum];

                curr[lastSum] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        // 1. Recursion
        // return maxTotalRewardRec(rewardValues,0,0);

        // 2. Memoization
        // vector<vector<int>> dp(2000,vector<int>(4000,-1));
        // return maxTotalRewardMem(rewardValues,0,0,dp);

        // 3. Tabulation
        // return maxTotalRewardTab(rewardValues);

        // 4. Space Optimization
        return maxTotalRewardSO(rewardValues);
    }
};