// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 


// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 
#include<iostream>
#include<vector>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1(Optimal)
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> out;
        for(int i=0;i<nums.size();i++){
            out.push_back({nums[i],i});
        }
        sort(out.begin(),out.end());
        int left=0;int right=nums.size()-1;
        while(left<right){
            if(out[left].first+out[right].first==target){
                return {out[left].second,out[right].second};
            }
            else if(out[left].first+out[right].first>target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1,-1};
        
    }
};