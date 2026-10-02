// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ 
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1(brute)
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        set<vector<int>> st;
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        if(i==j||i==k||j==k){
                            continue;
                        }
                        else{
                            vector<int> ar = {nums[i],nums[j],nums[k]};
                            sort(ar.begin(),ar.end());
                            st.insert(ar);
                        }
                    }
                }
            }
            
        }
        for(auto num:st){
            result.push_back(num);
        }
        return result;
    }
};
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-2(better)
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }
        set<vector<int>> uniqueTriplets;
        for (int first = 0; first < n - 2; first++) {
            unordered_set<long long> seenValues;
            for (int second = first + 1; second < n; second++) {
                long long thirdValue =
                    -(long long)(nums[first] + (long long)nums[second]);
                if (seenValues.find(thirdValue) != seenValues.end()) {
                    vector<int> triplet = {
                        nums[first],
                        nums[second],
                        (int) thirdValue
                    };
 
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
                seenValues.insert(nums[second]);
            }
        }
 
        return vector<vector<int>>(
            uniqueTriplets.begin(),
            uniqueTriplets.end()
        );
    }

};
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-3(optimal)
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return result;        
    }
};