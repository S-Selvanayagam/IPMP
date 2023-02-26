// leetcode https://leetcode.com/problems/remove-duplicate-letters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;
        stack<char> st;
        bool visited[26] = {false};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a'])
                continue;
            while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        string result;
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.removeDuplicateLetters("bcabc");
    cout<<s.removeDuplicateLetters("cbacdcbc");
    return 0;

}