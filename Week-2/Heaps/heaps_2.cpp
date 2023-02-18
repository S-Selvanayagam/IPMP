// GFG : finding sum of k most frequent elements in an array
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{
    public:
    int kMostFrequent(int arr[], int n, int k) 
    { 
        int ans =0;
        unordered_map<int,int> mp;
        priority_queue<int> pq;         //construct a max pq 
        for(int i=0; i<n;i++)
        {
            mp[arr[i]]++;               //count frequency of the elements
        }
        for(auto it:mp){
            pq.push(it.second);         // push the frequencies in max heap
        }
        for(int i =0; i<k;i++)
        {
            ans += pq.top();            // fetch the top
            pq.pop();
        }
        return ans;
    } 
};

int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
