// Problem: Maximum Difference
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m = nums[0]; int ans =0;
        for(int i=0; i<nums.size(); i++)
        {
            ans = max(ans, nums[i]-m);
            m = min(nums[i],m);
        }
        return ans==0? -1:ans;
    }
};