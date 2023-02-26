// Leetcode: https://leetcode.com/problems/next-greater-element-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);        
        if(s.length() == 1)
            return -1;
        int i = s.length() -1;          
        while(i>0)                      // find the first decreasing digit
        {
            if (s[i]> s[i-1]) break;
            i--;
        }
        if(i==0) return -1;               // if no decreasing digit found return -1
        int f = i-1;                       // f is the first decreasing digit
        int g = s.length()-1;              // g is the last digit
        while(f<g){                        // find the first digit greater than f
            if(s[g] > s[f]) break;
            g--;
        }                                   
        swap(s[f],s[g]);                    // swap f and g
        sort(s.begin()+i, s.end());         // sort the remaining digits
        try {
            long long ans = stoll(s);
            if(ans <= pow(2,31)-1)
                return stoi(s);
            else
                return -1;
        }catch (const std::invalid_argument& e) {
            return -1;
        }

    }
};

int main(){
    Solution s;
    cout<<s.nextGreaterElement(12);
    cout<<s.nextGreaterElement(21);
    cout<<s.nextGreaterElement(1999999999);
    return 0;

}