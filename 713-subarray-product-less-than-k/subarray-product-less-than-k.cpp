class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // Since k is positive, if k is 1 or less, no subarray can have a product less than k.
        
        int i = 0;
        int j = 0;
        int ans = 0;

        long long int prod = 1;
        while (j < nums.size()) {
            prod *= nums[j];
            while (prod >= k) {
                prod /= nums[i];
                i++;
            }
            ans += (j - i + 1); // Add the count of subarrays ending at j.
            j++;
        }
        return ans;
    }
};
