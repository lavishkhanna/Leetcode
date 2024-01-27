class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Check if the input array is empty. If it is, return 0 as there is no consecutive sequence.
        if (nums.empty()) {
            return 0;
        }

        // Step 2: Sort the input array in ascending order.
        sort(nums.begin(), nums.end());

        // Step 3: Initialize variables 'maxLength' and 'currentLength' to 1.
        int maxLength = 1;
        int currentLength = 1;

        // Step 4: Iterate through the sorted array, starting from the second element.
        for (int i = 1; i < nums.size(); ++i) {
            // Step 5: Check if the current number is not equal to the previous one.
            if (nums[i] != nums[i - 1]) {
                // Step 6: If the current number is one more than the previous one, it is part of the consecutive sequence.
                if (nums[i] == nums[i - 1] + 1) {
                    ++currentLength;
                } else {
                    // If not consecutive, reset the current length.
                    currentLength = 1;
                }

                // Step 7: Update the maximum length.
                maxLength = max(maxLength, currentLength);
            }
        }

        // Step 8: Return 'maxLength' as the length of the longest consecutive sequence.
        return maxLength;
    }
};