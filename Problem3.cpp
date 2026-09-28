// Given a string s, find the length of the longest substring without duplicate characters.
//_____________________________________________________________________________________________________________________________________________________________________________________________________________


// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
//_____________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 0 <= s.length <= 105
// s consists of English letters, digits, symbols and spaces.
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_set<char> current;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            while (current.find(s[right]) != current.end()) {
                current.erase(s[left]);
                left++;
            }
            current.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};