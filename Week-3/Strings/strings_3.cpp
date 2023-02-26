// Leetcode https://leetcode.com/problems/permutation-in-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(int i=0;i<s1.length();i++)
            freq1[s1[i]-'a']++;
        for(int i=0;i<s2.length();i++){                  // sliding window
            freq2[s2[i]-'a']++;
            if(i>=s1.length())                                                              
                freq2[s2[i-s1.length()]-'a']--;
            if(i>=s1.length()-1){
                bool flag = true;
                for(int j=0;j<26;j++)
                    if(freq1[j] != freq2[j]){
                        flag = false;
                        break;
                    }
                if(flag)
                    return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout<<s.checkInclusion("ab","eidbaooo");
    cout<<s.checkInclusion("ab","eidboaoo");
    return 0;

}