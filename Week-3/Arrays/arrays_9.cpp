// Leetcode : - https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// GFG : - https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays-of-different-sizes/0

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if(n>m) return findMedianSortedArrays(nums2, nums1);
    int low = 0;
    int high = n;
    while(low<=high)
    {
        int cut1 = (low+high)/2;
        int cut2 = (n+m+1)/2 - cut1;
        int l1 = (cut1==0)?INT_MIN:nums1[cut1-1];
        int l2 = (cut2==0)?INT_MIN:nums2[cut2-1];
        int r1 = (cut1==n)?INT_MAX:nums1[cut1];
        int r2 = (cut2==m)?INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1)
        {
            if((n+m)%2==0)
            {
                return (double)(max(l1,l2)+min(r1,r2))/2;
            }
            else{
                return (double)max(l1,l2);
            }
        }
        else if(l1>r2)
        {
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 0.0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v1(n);
        vector<int> v2(m);
        for(int i = 0; i < n; i++)
        {
            cin>>v1[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin>>v2[i];
        }
        cout<<findMedianSortedArrays(v1,v2)<<endl;
    }
    return 0;
}