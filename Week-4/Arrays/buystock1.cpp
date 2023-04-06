// Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// GFG: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int m = prices[0];
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, prices[i]-m);
        m = min(prices[i], m);
    }
    return ans;
}