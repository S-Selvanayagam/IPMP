// gfg - add two numbers represented by linked lists
#include <bits/stdc++.h>

using namespace std;
class Solution{
public:  
    vector<int> findSum(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        int carry = 0;
        vector<int> ans;
        int i = n-1, j = m-1;
        while (i >= 0 && j >= 0) {
            int sum = a[i] + b[j] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = a[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            i--;
        }
        while (j >= 0) {
            int sum = b[j] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            j--;
        }
        if (carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}