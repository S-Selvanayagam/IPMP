// Leetcode 34. Find First and Last Position of Element in Sorted Array
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> searchRange(vector<int>& a, int target) {
    int l = 0, r = a.size()-1;
    vector<int> ans(2, -1);

    // Find first occurrence
    while(l <= r){
        int m = l + (r-l)/2;
        if(a[m] < target)
            l = m+1;
        else if(a[m] > target)
            r = m-1;
        else{
            if(m == l || a[m] != a[m-1]){
                ans[0] = m;
                break;
            }
            else
                r = m-1;
        }
    }

    // Find last occurrence
    l = 0, r = a.size()-1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(a[m] < target)
            l = m+1;
        else if(a[m] > target)
            r = m-1;
        else{
            if(m == r || a[m] != a[m+1]){
                ans[1] = m;
                break;
            }
            else
                l = m+1;
        }
    }
    return ans;
}

};