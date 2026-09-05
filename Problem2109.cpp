// You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.

// For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
// Return the modified string after the spaces have been added.

// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


// Example 1:

// Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
// Output: "Leetcode Helps Me Learn"
// Explanation: 
// The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
// We then place spaces before those characters.

// Example 2:

// Input: s = "icodeinpython", spaces = [1,5,7,9]
// Output: "i code in py thon"
// Explanation:
// The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
// We then place spaces before those characters.

// Example 3:

// Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
// Output: " s p a c i n g"
// Explanation:
// We are also able to place spaces before the first character of the string.
 
// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists only of lowercase and uppercase English letters.
// 1 <= spaces.length <= 3 * 105
// 0 <= spaces[i] <= s.length - 1
// All the values of spaces are strictly increasing.
// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int g = s.length();
        int n = spaces.size();
        string result;
        for(int i=0;i<n;i++){
            if(i==0){
                result += s.substr(0,spaces[i])+" ";
            }
            else{
                result += s.substr(spaces[i-1],spaces[i]-spaces[i-1])+" ";
            }
        }
        result += s.substr(spaces[n-1],g-spaces[n-1]);
        return result;
    }
};
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-2
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int a =s.length();
        int b = spaces.size();
        result.reserve(a+b);
        int j = 0;
        for(int i=0;i<a;i++){
            if(j<b && i==spaces[j]){
                result += " ";
                j++;
            }
            result += s[i];
        }
        return result;
    }
};