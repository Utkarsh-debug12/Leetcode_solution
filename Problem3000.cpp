//Problem 3000-Leetcode
// You are given a 2D 0-indexed integer array dimensions.
// For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
// Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

#include<iostream>
#include<vector>
using namespace std;

// Method 1

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0,current_area,diagonal = 0,current_diagonal;
        for(const auto& num : dimensions){
            current_diagonal = num[0]*num[0] + num[1]*num[1];
            if (current_diagonal > diagonal){
                diagonal = current_diagonal;
                area = num[0]*num[1];
            }
            else if(current_diagonal == diagonal){
                current_area = num[0]*num[1];
                if(current_area>area){
                    area = current_area;
                }
            }
        }
        return area;
    }
};