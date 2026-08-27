// You are given a positive integer n.

// Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.

// An integer is called good if squareSum - digitSum >= 50.

// Return true if n is good. Otherwise, return false.

//________________________________________________________________________________________________________________________________________________________________________________________________________________

// Example 1:

// Input: n = 1000

// Output: false

// Explanation:

// The digits of 1000 are 1, 0, 0, and 0.
// The digitSum is 1 + 0 + 0 + 0 = 1.
// The squareSum is 12 + 02 + 02 + 02 = 1.
// The squareSum - digitSum is 1 - 1 = 0. As 0 is not greater than or equal to 50, the output is false.

// Example 2:

// Input: n = 19

// Output: true

// Explanation:

// The digits of 19 are 1 and 9.
// The digitSum is 1 + 9 = 10.
// The squareSum is 12 + 92 = 1 + 81 = 82.
// The squareSum - digitSum is 82 - 10 = 72. As 72 is greater than or equal to 50, the output is true.
 
//________________________________________________________________________________________________________________________________________________________________________________________________________________

// Constraints:

// 1 <= n <= 109

//________________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
using namespace std;

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________

// Method 1:

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq_sum = 0,sum = 0,rem;
        while(n != 0 ){
            rem = n%10;
            sum += rem;
            sq_sum += rem*rem;
            n = n/10;
        }
        return sq_sum-sum>=50;
    }
};

