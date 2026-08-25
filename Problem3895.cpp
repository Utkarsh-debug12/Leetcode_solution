// You are given an integer array nums and an integer digit.

// Return the total number of times digit appears in the decimal representation of all elements in nums.

//_________________________________________________________________________________________________________________________________________________________________________________________________

// Example 1:

// Input: nums = [12,54,32,22], digit = 2

// Output: 4

// Explanation:

// The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.



// Example 2:

// Input: nums = [1,34,7], digit = 9

// Output: 0

// Explanation:

// The digit 9 does not appear in the decimal representation of any element in nums, so the total number of times digit 9 appears is 0.

//________________________________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 10^6​​​​
// 0 <= digit <= 9

//________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

// this is code is universally acceptable

//________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<vector>
using namespace std;

//_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
// Method 1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int result = 0;
        for(auto& num:nums){
            long long x = abs((long long)num);

            // In a 32-bit system, the maximum positive integer is 2147483647, but the minimum negative integer is -2147483648.
            // Because the negative side has one extra number, abs(-2147483648) overflows and actually returns a negative number!
            // So we use 'long long', a larger data type before taking the absolute value to bulletproof our code.

            // In C++, the modulo operator on a negative number returns a negative remainder.
            // For example, -15 % 10 evaluates to -5. If your array has negative numbers,
            // your code will fail to match them against a positive digit.

        
            int rem;
            do{
                rem = x%10;
                if(rem == digit){
                    result += 1;
                }
                x = x/10;
            }while(x != 0);

            //If your array contains the number 0 (e.g., nums = [0, 10, 20]) and you are searching for digit = 0, your code will miss the standalone 0.
            //Why? Because if x = 0, the loop condition while (x != 0) immediately evaluates to false, skipping the number entirely.

        }
        return result;
    }
};

