// Leetcode https://leetcode.com/problems/first-unique-character-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;
        cout<<s<<endl;
        for(int i=0;i<s.length();i++)
            cout<<s[i]<<freq[s[i]-'a']<<" ";
            cout<<endl;
        for(int i=0;i<s.length();i++)
            if(freq[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode");
    cout<<s.firstUniqChar("loveleetcode");
    return 0;

}