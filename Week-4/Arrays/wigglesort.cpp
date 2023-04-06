// Leetcode: https://leetcode.com/problems/wiggle-sort-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> larger(nums.begin(), nums.begin() + n/2);
        vector<int> smaller(nums.begin() + n/2, nums.end());
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                nums[i] = smaller[i/2];
            } else {
                nums[i] = larger[i/2];
            }
        }
    }

};