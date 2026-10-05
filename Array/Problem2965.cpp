// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

// Example 2:

// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
// Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 
// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


// Constraints:

// 2 <= n == grid.length == grid[i].length <= 50
// 1 <= grid[i][j] <= n * n
// For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
// For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
// For all x that 1 <= x <= n * n except two of them there is exactly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.
// _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
using namespace std;
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
//Method-1
//_____________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1;
        int twice = -1;
        int l = (n*n)+1;
        vector<int> count(l,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int h = grid[i][j];
                count[h]++;
            }
        }
        for(int i = 1;i<l;i++){
            if(count[i]==0){
                missing = i;
            }
            else if(count[i]==2){
                twice  = i;
            }
            if(missing!=-1 && twice!=-1){
                break;
            }
        }
        return {twice,missing};
    }
};