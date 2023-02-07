#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /* if x is present in arr[] then returns the count
    	of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x) {
      // code here
      int l = 0;
      int r = n - 1;
      int f = -1, e = -1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else if (arr[mid] > x) r = mid - 1;
        else {
          e = mid;
          r = mid - 1;
        }
      }
      l = 0;
      r = n - 1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else if (arr[mid] > x) r = mid - 1;
        else {
          f = mid;
          l = mid + 1;
        }
      }
      if (f == -1) {
        return 0;
      } 
      else {
        return f - e + 1;
      }
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
    auto ans = ob.count(arr, n, x);
    cout << ans << "\n";
  }
  return 0;
}
