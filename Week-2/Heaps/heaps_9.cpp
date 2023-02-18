// gfg - kth largest element in a stream
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(arr[i]);
        }
        while(k>1)
        {
            k--;
            pq.pop();
        }
        return pq.top();
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
}