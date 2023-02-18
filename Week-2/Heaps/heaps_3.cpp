// GFG Problem: Minimum Cost of ropes
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        
        long long ans=0;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for (long long i=0; i<n; i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size()>1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long c = a+b;
            ans+=c;
            pq.push(c);
        }
        return ans;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
