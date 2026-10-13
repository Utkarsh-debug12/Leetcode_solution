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
        sort(nums.begin(),nums.end());
        int result;
        int diff =INT_MAX;
        int n = nums.begin();
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                sum = nums[i]+nums[j]+nums[k];
                int d = abs(target-sum);
                if(d<diff){
                    diff = d;
                    result = sum;
                    left
                }
                
            }
        }
    }
};