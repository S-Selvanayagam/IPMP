// Leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m =0;
        set<int> s1;
        for(int i=0; i<s.length(); i++)
        {
            int j = i;
            while(s1.size() == j-i && j<s.length())
            {
                s1.insert(s[j]);
                j++;
            }
            int a = s1.size();
            m = max(m,a);
            s1.clear();
        }
        return m;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ob;
    int ans = ob.lengthOfLongestSubstring(s);
    cout<<ans<<endl;
}