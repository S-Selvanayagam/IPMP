#include<iostream>
using namespace std;

int binarysearch(int arr[], int l, int r, int k)
{
    int m;
    while(l<=r)
    {
        m = l + (r-l)/2;
        if(arr[m] == k) return m;
        if(arr[m] > k) r = m-1;
        if(arr[m] < k) l = m+1;    
    }
    return -1;
}

int main()
{
    int n,k;
    cin>>n;
    cout<<"elements of the array"<<endl;
    int arr[n];
    for(auto i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"search key: "<<endl;
    cin>>k;
    int ans = binarysearch(arr,0,n-1,k);
    if(ans == -1) {cout<<"not there"<<endl;}
    else{cout<<"index :"<<ans<<endl;}
    return 0;
}

// time complexity - O(logn)
// space complexity - O(1)
// more memory efficient than recursive due to constant memory usage compared to Recursive (higher due to recursive stack call)
