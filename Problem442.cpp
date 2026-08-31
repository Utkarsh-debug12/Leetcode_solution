// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

//_____________________________________________________________________________________________________________________________________________________________________________________________________________

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:

// Input: nums = [1,1,2]
// Output: [1]

// Example 3:

// Input: nums = [1]
// Output: []
 
//_____________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
// Method 1
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        map<int,int> out;
        for(auto& num:nums){
            if(out.find(num)!=out.end()){
                out[num] += 1;
            }
            else{
                out[num] = 1;
            }
        }
        for(auto h:out){
            if(h.second==2){
                result.push_back(h.first);
            }
        }
        return result;
    }
};