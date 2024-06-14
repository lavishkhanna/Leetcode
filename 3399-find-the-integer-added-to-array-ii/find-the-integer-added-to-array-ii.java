class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        int n = nums1.length;

        // find top 3 smallest elements in nums1:
        int min1_1 = Integer.MAX_VALUE, min1_2 = Integer.MAX_VALUE, min1_3 = Integer.MAX_VALUE;
        for (int val : nums1) {
            if (val < min1_1) {
                min1_3 = min1_2;
                min1_2 = min1_1;
                min1_1 = val;
            } else if (val < min1_2) {
                min1_3 = min1_2;
                min1_2 = val;
            } else if (val < min1_3) {
                min1_3 = val;
            }
        }
        
        // find the smallest element in nums2
        int min2 = Integer.MAX_VALUE;
        for (int val : nums2) {
            min2 = Math.min(min2, val);
        }
        // the 3 only possible x values:
        int[] candidates = new int[] {min2 - min1_1, min2 - min1_2, min2 - min1_3};
        
        // count the occurrences of each number in nums1: 
        int[] numberOccurs = new int[1001];
        for (int i = 0; i < n; i++) {
            int n1 = nums1[i];
            numberOccurs[n1]++;
        }

        int minX = Integer.MAX_VALUE;
        for (int possibleX : candidates) {
            int[] numberCounts = new int[1001];
            boolean isPossible = true;
            // iterate nums2 to check whether the value of 'nums2[i] - possibleX' exists for every element
            for (int i = 0; i < n - 2 && isPossible; i++) {
                int target = nums2[i] - possibleX;
                if (target < 0 || target > 1000 || numberOccurs[target] == 0 || numberCounts[target] == numberOccurs[target]) {
                    isPossible = false;
                } else {
                    numberCounts[target]++;
                }
            }
            if (isPossible) {
                minX = Math.min(minX, possibleX);
            }
        }
        return minX;
    }
}