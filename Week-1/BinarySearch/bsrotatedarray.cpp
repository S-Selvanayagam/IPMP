//Leetcode: 153 - Find Minimum in rotated sorted array

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size()-1;
        while(l<r)
        {
            if(nums[l] < nums[r]){return nums[l];}   //as it should be if no rotate
            int m = l+(r-l)/2;
            if(nums[m]>=nums[l]){l = m+1;}           // our inflection did not happen yet, hence we bring the pointer closer
            else{r = m;}                             // inflection happened between 0 and m itself so reducing the right pointer.
        }
        return nums[l];
    }
};