//Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
// GFG Length Unsorted Subarray
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    int s = 0, e = n-1;
        while(s<n-1 && arr[s] <= arr[s+1]) s++;
        if(s==n-1){
            return {0,0};
        }
        while(e>0 && arr[e] >= arr[e-1]) e--;
        int min_val= arr[s], max_val = arr[s];
        for(int i=s+1; i<=e;i++)
        {
            min_val = min(min_val,arr[i]);
            max_val = max(max_val,arr[i]);
        }
        while (s > 0 && arr[s - 1] > min_val) s--;
        while (e < n - 1 && arr[e + 1] < max_val) e++;
        vector<int> ans;
        ans.push_back(s);
        ans.push_back(e);
        return ans;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

