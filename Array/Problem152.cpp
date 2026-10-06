// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

//_____________________________________________________________________________________________________________________________________________________________________________________________________________


// ​​​​​​​Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
//_____________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1(Optimal)
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = min({curr, max_so_far * curr, min_so_far * curr});
            max_so_far = temp_max;
            result = max(result, max_so_far);
        }
        return result;
    }
};