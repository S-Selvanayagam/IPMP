// gfg - pair with given sum
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int c = x - arr[i];
            if(s.find(c) != s.end()) return true;
            s.insert(arr[i]);
        }
        return false;
        
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
