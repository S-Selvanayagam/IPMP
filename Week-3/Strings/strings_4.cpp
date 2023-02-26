// Leetcode https://leetcode.com/problems/reverse-words-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            if (i >= s.length()) {
                break;
            }
            int j = i + 1;
            while (j < s.length() && s[j] != ' ') {
                j++;
            }
            string word = s.substr(i, j - i);
            if (result.length() == 0) {
                result = word;
            } else {
                result = word + " " + result;
            }
            i = j + 1;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.reverseWords("the sky is blue");
    return 0;

}