//gfg https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findLeft(int arr[], int n)
    {
        vector<int> v(n);
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && s.top() >= arr[i])
                s.pop();
            if(s.empty()) v[i] = 0;
            else v[i] = s.top();
            
            s.push(arr[i]);
        }
        return v;
    }
    
    vector<int> findRight(int arr[], int n)
    {
        vector<int> v(n);
        stack<int> s;
        for(int i = n - 1 ; i >= 0; i--)
        {
            while(!s.empty() && s.top() >= arr[i])
                s.pop();
            if(s.empty()) v[i] = 0;
            else v[i] = s.top();
            
            s.push(arr[i]);
        }
        return v;
    }
    
    int findMaxDiff(int A[], int n)
    {
        vector<int> left = findLeft(A, n);
        vector<int> right = findRight(A, n);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, abs(left[i] - right[i]));
        }
        return ans;
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}
