// class Solution {
// public:
//     long long largestPerimeter(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), greater<int>());
        
//         long long net=0;
//         for(int i=0;i<nums.size();i++){
//             net=net+nums[i];
//         }
        
//         for(int i=0;i<nums.size();i++){
//             int left=net-nums[i];
//             if(left>nums[i]){
//                 return left+nums[i];
//             }
//             else{
//                 net=net-nums[i];
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());  // sort in descending order
        
        long long net = 0;
        for (int i = 0; i < nums.size(); i++) {
            net = net + static_cast<long long>(nums[i]);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            long long left = net - static_cast<long long>(nums[i]);
            if (left > static_cast<long long>(nums[i])) {
                return left + static_cast<long long>(nums[i]);
            } else {
                net = net - static_cast<long long>(nums[i]);
            }
        }
        return -1;
    }
};