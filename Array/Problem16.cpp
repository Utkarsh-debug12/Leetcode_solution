// You are given an integer array nums of length n and an integer target.

// Find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 


// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 
#include<iostream>
#include<vector>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0; 
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];  
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                if (current_sum < target) {
                    ++left;
                } else if (current_sum > target) {
                    --right;
                } else {
                    return current_sum;
                }
            }
        }
        return closest_sum;
    }
};