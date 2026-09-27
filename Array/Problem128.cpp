// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

//_____________________________________________________________________________________________________________________________________________________________________________________________________________


// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3
 
//_____________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(auto num:nums){
            st.insert(num);
        }
        int longest = 1;
        
        for(auto s:st){
            if(st.find(s-1)==st.end()){
                int count = 1;
                int x = s;
                while(st.find(x+1)!=st.end()){
                    x++;
                    count++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};