// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num: nums)
        {
            mp[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i = mp.begin();i!= mp.end(); i++)
        {
            pq.push(make_pair(i->second, i->first));
            if(pq.size() > mp.size() - k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};