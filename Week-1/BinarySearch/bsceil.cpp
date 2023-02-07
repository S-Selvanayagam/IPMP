#include<iostream>
#include<vector>
using namespace std;


int ceilsearch(vector<int>& arr,int l,int h,int k)
{
    int mid;
    while(l<=h)
    {
        mid = l +(h-l)/2;
        if(arr[mid] == k){return mid;}
        else if(k<arr[mid]){h = mid-1;}
        else {l=mid+1;}
    }
    return l;
}


int main()
{
    int n; cout<<"Enter size of the array"<<endl; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k; cout<<"Enter search key to find ceil of"<<endl; cin>>k;
    int result = ceilsearch(arr, 0, n-1, k);
    cout<<result;
    if (result >= n) {
    cout << "No ceil found for " << k << endl;
    } else {
    cout << "Ceiling of " << k << " is at index " << result << endl;
    }
    return 0;
}